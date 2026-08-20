#!/usr/bin/env python3

import os
import re
import subprocess
from typing import List


def check_tools() -> None:
    command = ['which', 'hub']
    ret_code = subprocess.call(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    if ret_code != 0:
        raise Exception("Error: command 'hub' is not installed")


def create_tag() -> str:
    subprocess.check_call(['git', 'fetch', '--tags'])
    # create new tag as per current release
    command = ['git', 'tag']
    tags = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE).stdout.read()

    tags = tags.decode(encoding='utf-8')
    current_tag = tags.splitlines()[-1]

    if not re.match("^v[0-9]+[.][0-9]", current_tag):
        raise Exception("Error: tag name does not follow expected pattern.")

    version = current_tag[1:].split('.')

    major_version = int(version[0])
    minor_version = int(version[1])
    increment, new_minor_version = divmod(minor_version + 1, 10)

    new_tag = f"v{major_version + increment}.{new_minor_version}"
    print(f"===== New tag created: {new_tag}")
    return new_tag


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


def call_hub_release(attachments:List[str], message, tag):
    try:
        release_command = ['hub', 'release', 'create', '--browse', f'--message={message}', tag] + \
            ['--attach=' + s for s in attachments]
        pipe = None
        subprocess.check_call(
            release_command,
            stdout=pipe,
            stderr=pipe)
    except subprocess.CalledProcessError as e:
        print("Error: hub release failed", e)
        print("If it is username/password related:")
        print("\t1. go to https://github.com/settings/tokens/, and create a token.")
        print("\t2. the token should be in the repo and gist scope.")
        print("\t3. input the token as the password.")
        raise e


def main():
    # ensure in root folder
    if not os.path.exists("WORKSPACE"):
        raise Exception('ERROR: This script should be run in the root folder of the project.')

    githubTokenKey = "GITHUB_TOKEN"
    if githubTokenKey not in os.environ:
        print("Need to define the environment variable %s" % githubTokenKey)
        exit(1)

    # check prerequisite tools
    check_tools()

    tag_name = create_tag()
    title = f"Perses {tag_name}"

    # get built binary path
    perses_binary_path = build_perses_binary()

    # check pre-submit conditions
    check_version(perses_binary_path, tag_name)
    check_repository()

    kitten_binary_path = build_kitten_binary()
    kitten_organizer_binary_path = build_kitten_organizer_binary()

    # release
    call_hub_release(
        attachments=[perses_binary_path, kitten_binary_path, kitten_organizer_binary_path],
        message=title,
        tag=tag_name
    )

    print("Released successfully!")

if __name__ == "__main__":
    main()
