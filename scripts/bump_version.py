#!/usr/bin/env python3
"""Bumps the release version.

Rewrites the VERSION file (the single source the generated Version class is
built from) and regenerates the golden files derived from it (README.md's
download link, the readme HTML golden). With no argument, bumps to the
successor of the latest release tag.
"""

import argparse
import subprocess
from pathlib import Path

import generate_release_notes

VERSION_FILE = Path('version/org/perses/version/VERSION')


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        'version', nargs='?',
        help='the new version; must be exactly the successor of the latest '
             'release tag (also the default): minor + 1, single digit, with '
             'the major bumped only when the minor rolls over from 9')
    flags = parser.parse_args()

    if not Path('WORKSPACE').exists():
        raise Exception(
            'ERROR: This script should be run in the root folder of the project.')

    current_tag = generate_release_notes.latest_release_tag()
    next_tag = generate_release_notes.next_release_tag(current_tag)
    if flags.version is not None and f'v{flags.version}' != next_tag:
        raise Exception(
            f'Error: the successor of {current_tag} is {next_tag}; versions '
            f'must not skip forward or backward, so {flags.version!r} is not '
            'allowed.')

    # The target is the successor of the tag RELEASED on GitHub, not of the
    # VERSION file, so rerunning this script never bumps twice: the target
    # only advances once a release publishes the new tag.
    assert next_tag.startswith('v'), next_tag
    new_version = next_tag[1:]
    if VERSION_FILE.read_text().strip() == new_version:
        print(f'{VERSION_FILE} is already at {new_version}.')
    else:
        VERSION_FILE.write_text(f'{new_version}\n')
        print(f'Updated {VERSION_FILE} to {new_version}.')
    subprocess.check_call(['./scripts/update_golden_files.sh'])
    print('Bumped and regenerated the goldens. Run ./scripts/presubmit.sh to verify.')


if __name__ == '__main__':
    main()
