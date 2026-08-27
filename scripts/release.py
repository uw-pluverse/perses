#!/usr/bin/env python3

import argparse
import os
import subprocess
import tempfile
from typing import List

# release.py is run as a script, so its directory is on sys.path.
import generate_release_notes


def check_tools() -> None:
    command = ['which', 'gh']
    ret_code = subprocess.call(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    if ret_code != 0:
        raise Exception("Error: command 'gh' is not installed (https://cli.github.com)")


def check_version_file(tag_name) -> None:
    # Fails before the build if the bump was forgotten; the built jar's
    # --version output is still the authoritative check afterwards.
    version = open('version/org/perses/version/VERSION').read().strip()
    if f'v{version}' != tag_name:
        raise Exception(
            f"ERROR: the VERSION file says {version} but the release is "
            f"{tag_name}. Run ./scripts/bump_version.py and commit first.")
    print("===== * PASSED : VERSION file matches the release")


def create_tag() -> str:
    current_tag = generate_release_notes.latest_release_tag()
    new_tag = generate_release_notes.next_release_tag(current_tag)
    print(f"===== New tag created: {new_tag}")
    return new_tag


def check_head_is_pushed() -> str:
    # The release tags whatever commit is released, so HEAD must already be on
    # the remote master: releasing an unpushed HEAD would tag a commit whose
    # source does not match the released jar.
    subprocess.check_call(['git', 'fetch', '--quiet', 'origin', 'master'])
    head = subprocess.check_output(['git', 'rev-parse', 'HEAD'], text=True).strip()
    remote = subprocess.check_output(['git', 'rev-parse', 'FETCH_HEAD'], text=True).strip()
    if head != remote:
        raise Exception(
            f"ERROR: HEAD ({head[:9]}) is not the remote master ({remote[:9]}). "
            "Push (or pull --rebase) first, then rerun the release.")
    print("===== * PASSED : HEAD is the pushed remote master")
    return head


def _build_binary(binary_name:str, build_path:str) -> None:
    print("----- Building %s binary..." % binary_name)
    build_command = ['bazelisk', 'build', build_path]

    subprocess.check_call(
        build_command,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL)


def build_perses_binary() -> str:
    _build_binary(binary_name='perses', build_path='//src/org/perses:perses_deploy.jar')
    return 'bazel-bin/src/org/perses/perses_deploy.jar'


def build_kitten_binary() -> str:
    _build_binary(binary_name='kitten', build_path='//kitten/src/org/perses/fuzzer:kitten_deploy.jar')
    return 'bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar'


def build_kitten_organizer_binary() -> str:
    _build_binary(binary_name='kitten_organizer', build_path='//kitten/src/org/perses/fuzzer/organizer:kitten_organizer_deploy.jar')
    return 'bazel-bin/kitten/src/org/perses/fuzzer/organizer/kitten_organizer_deploy.jar'


def check_version(jar_path: str, release_version: str):
    # return True if perses version is consistent with current releasing version
    command = ['java', '-jar', f'{jar_path}', '--version', ]
    version_info = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE).stdout.read()

    version_info = version_info.decode(encoding='utf-8')
    perses_version_number = version_info.splitlines()[0].split()[-1]

    print(f"===== Perses version: v{perses_version_number}; Release version: {release_version}")

    assert release_version.startswith('v'), release_version
    if perses_version_number != release_version[1:]:
        raise Exception("Error: Perses version check fails. Update version info in source code and commit.")
    print("===== * PASSED : Version check")
    return


def check_repository():
    # return True if repository is not clean (has uncommitted changes)
    # Note: the following command ignores untracked files (newly added files)
    command = ['git', 'diff-index', '--quiet', 'HEAD', '--']
    return_code = subprocess.call(command)

    print(f"===== Repo return code = {return_code}")
    if return_code != 0:
        raise Exception("ERROR: Repository not clean. Check uncommitted changes.")
    print("===== * PASSED : Repository check")
    return


def call_gh_release(attachments:List[str], notes_file, tag, target_commit):
    # The first line of the notes file is the release title, the rest the body.
    with open(notes_file) as file:
        title, body = (file.read().split('\n', 1) + [''])[:2]
    with tempfile.NamedTemporaryFile(mode='w', suffix='.md') as body_file:
        body_file.write(body.lstrip('\n'))
        body_file.flush()
        # --target pins the tag to the verified commit instead of whatever the
        # remote HEAD is by the time the release request lands.
        release_command = ['gh', 'release', 'create', tag,
                           f'--target={target_commit}',
                           f'--title={title}',
                           f'--notes-file={body_file.name}'] + attachments
        subprocess.check_call(release_command)


def prepare_notes_file(notes_file, tag_name) -> str:
    if notes_file:
        return notes_file
    notes = generate_release_notes.render_notes(
        tag_name,
        generate_release_notes.commit_subjects(
            generate_release_notes.latest_release_tag()))
    print("===== Release notes:\n" + notes)
    with tempfile.NamedTemporaryFile(
            mode='w', suffix='.md', delete=False) as file:
        file.write(notes)
        return file.name


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        '--notes-file',
        help='release title (first line) and notes; default: generated from '
             'the conventional-commit history since the previous tag')
    flags = parser.parse_args()

    # ensure in root folder
    if not os.path.exists("WORKSPACE"):
        raise Exception('ERROR: This script should be run in the root folder of the project.')

    githubTokenKey = "GITHUB_TOKEN"
    if githubTokenKey not in os.environ:
        print("Need to define the environment variable %s" % githubTokenKey)
        exit(1)

    # check prerequisite tools
    check_tools()

    check_repository()
    target_commit = check_head_is_pushed()

    tag_name = create_tag()
    check_version_file(tag_name)
    notes_file = prepare_notes_file(flags.notes_file, tag_name)

    # get built binary path
    perses_binary_path = build_perses_binary()
    check_version(perses_binary_path, tag_name)

    kitten_binary_path = build_kitten_binary()
    kitten_organizer_binary_path = build_kitten_organizer_binary()

    # release
    call_gh_release(
        attachments=[perses_binary_path, kitten_binary_path, kitten_organizer_binary_path],
        notes_file=notes_file,
        tag=tag_name,
        target_commit=target_commit
    )

    print("Released successfully!")

if __name__ == "__main__":
    main()
