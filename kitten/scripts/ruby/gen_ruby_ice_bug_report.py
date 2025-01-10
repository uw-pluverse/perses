#!/usr/bin/env python3

import urllib.request
import sys
import subprocess
import os


def read_source_file(source_file: str) -> str:
    with open(source_file, "r") as f:
        return f.read().strip()


def compute_compiler_version(ruby: str) -> str:
    return subprocess.check_output(
        [ruby, '-version'],
        stderr=subprocess.STDOUT).decode('utf-8').strip().splitlines()[-1]


def run_compiler_to_collect_output(
        compiler: str,
        flags: str,
        source_file: str
) -> str:
    cmd = f'{comiler} {flags} {source_file}'.split()
    return subprocess.run(
        cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT).stdout.decode('utf-8').strip()


def get_system_information() -> str:
    cmd = 'uname --kernel-name --kernel-release --machine --operating-system'.split()
    return subprocess.run(
        cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT).stdout.decode('utf-8').strip()


def main(ruby: str, flags: str, source_file: str):
    EMPTY = ''
    lines = [
        '## Compiler Version',
        EMPTY,
        '```',
        compute_compiler_version(ruby),
        '```',
        EMPTY,
        '## System Information',
        EMPTY,
        '```',
        get_system_information(),
        '```',
        EMPTY,
        '## Minimized Code',
        EMPTY,
        '```ruby',
        read_source_file(source_file),
        '```',
        EMPTY,
        '## Output (click arrow to expand)',
        EMPTY,
        '<details>',
        EMPTY,
        '```ruby',
        run_compiler_to_collect_output(ruby, flags, source_file),
        '```',
        '</details>'
    ]
    for l in lines:
        print(l)


if __name__ == '__main__':
    if len(sys.argv) != 4:
        print('Usage: %s <ruby> <flags> <source file>' % sys.argv[0])
        exit(1)
    main(ruby=sys.argv[1], flags=sys.argv[2], source_file=sys.argv[3])
