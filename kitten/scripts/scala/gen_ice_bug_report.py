#!/usr/bin/env python3

import urllib.request
import sys
import subprocess
import os


def read_source_file(source_file: str) -> str:
    with open(source_file, "r") as f:
        return f.read().strip()


def compute_compiler_version(scalac: str) -> str:
    return subprocess.check_output(
        [scalac, '-version'],
        stderr=subprocess.STDOUT).decode('utf-8').strip().splitlines()[-1]


def run_compiler_to_collect_output(
        comiler: str,
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


def main(scalac: str, flags: str, source_file: str):
    EMPTY=''
    lines = [
        '## Compiler Version',
        EMPTY,
        '```',
        compute_compiler_version(scalac),
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
        '```scala',
        read_source_file(source_file),
        '```',
        EMPTY,
        '## Output (click arrow to expand)',
        EMPTY,
        '<details>',
        EMPTY,
        '```scala',
        run_compiler_to_collect_output(scalac, flags, source_file),
        '```',
        '</details>'
    ]
    for l in lines:
        print(l)


if __name__ == '__main__':
    if len(sys.argv) != 4:
        print('Usage: %s <scalac> <flags> <source file>' % sys.argv[0])
        exit(1)
    main(scalac=sys.argv[1], flags=sys.argv[2], source_file=sys.argv[3])
