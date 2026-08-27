#!/usr/bin/env python3
"""Generates release notes from the conventional-commit history.

Collects the commits since the previous release tag (the highest vMAJOR.MINOR
tag), groups their subjects by conventional-commit type, and prints markdown
whose first line is the release title -- the format `hub release create -F`
and `gh release create --notes-file` expect.
"""

import argparse
import re
import subprocess
from typing import Dict, List, Optional, Tuple

TAG_PATTERN = re.compile(r'^v(\d+)\.(\d+)$')
# type(scope)!: description
SUBJECT_PATTERN = re.compile(r'^(?P<type>[a-z]+)(\([^)]+\))?(?P<breaking>!)?: (?P<description>.+)$')

SECTIONS = [
    ('breaking', 'Breaking changes'),
    ('feat', 'New features'),
    ('fix', 'Bug fixes'),
    ('improvement', 'Improvements'),
    ('other', 'Other changes'),
]
# docs/test/chore/build/ci/style/revert are internal housekeeping; they carry
# no user-visible change, so they stay out of the notes.
TYPE_TO_SECTION = {
    'feat': 'feat',
    'fix': 'fix',
    'perf': 'improvement',
    'refactor': 'improvement',
}


def _run(command: List[str]) -> str:
    return subprocess.run(
        command, check=True, capture_output=True, text=True).stdout


def parse_tag(tag: str) -> Optional[Tuple[int, int]]:
    match = TAG_PATTERN.match(tag)
    return (int(match.group(1)), int(match.group(2))) if match else None


def latest_release_tag() -> str:
    versions = [v for v in
                (parse_tag(t) for t in _run(['git', 'tag']).splitlines())
                if v is not None]
    if not versions:
        raise Exception('Error: found no tag matching vMAJOR.MINOR.')
    return 'v%d.%d' % max(versions)


def next_release_tag(current_tag: str) -> str:
    major, minor = parse_tag(current_tag)
    increment, new_minor = divmod(minor + 1, 10)
    return f'v{major + increment}.{new_minor}'


def commit_subjects(since_tag: str) -> List[str]:
    return _run(
        ['git', 'log', '--no-merges', '--format=%s', f'{since_tag}..HEAD']
    ).splitlines()


def group_subjects(subjects: List[str]) -> Dict[str, List[str]]:
    groups: Dict[str, List[str]] = {key: [] for key, _ in SECTIONS}
    for subject in subjects:
        match = SUBJECT_PATTERN.match(subject)
        if not match:
            # Non-conventional subject (e.g. an externally merged PR).
            groups['other'].append(subject)
        elif match.group('breaking'):
            groups['breaking'].append(match.group('description'))
        elif match.group('type') in TYPE_TO_SECTION:
            groups[TYPE_TO_SECTION[match.group('type')]].append(
                match.group('description'))
    return groups


def render_notes(next_tag: str, subjects: List[str]) -> str:
    lines = [f'Perses {next_tag}', '']
    groups = group_subjects(subjects)
    for key, heading in SECTIONS:
        if not groups[key]:
            continue
        lines.append(f'## {heading}')
        lines.extend(f'- {description}' for description in groups[key])
        lines.append('')
    if len(lines) == 2:
        lines.append('Maintenance release.')
        lines.append('')
    return '\n'.join(lines)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        '--next-tag',
        help='the tag being released; default: the successor of the latest tag')
    flags = parser.parse_args()

    previous_tag = latest_release_tag()
    next_tag = flags.next_tag or next_release_tag(previous_tag)
    print(render_notes(next_tag, commit_subjects(previous_tag)), end='')


if __name__ == '__main__':
    main()
