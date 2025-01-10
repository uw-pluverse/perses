#!/usr/bin/env python3

import urllib.request
import sys
import subprocess
import os


def read_source_file(source_file: str) -> str:
    with open(source_file, "r") as f:
        return f.read().strip()


def compute_compiler_version(compiler: str) -> str:
    return subprocess.check_output(
        [compiler, '--version'],
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


def main(compiler: str, flags: str, source_file: str):
    EMPTY=''
    lines = [
        '## Compiler Version',
        EMPTY,
        '```',
        compute_compiler_version(compiler),
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
        '```',
        read_source_file(source_file),
        '```',
        EMPTY,
        '## Output',
        EMPTY,
        '```',
        run_compiler_to_collect_output(compiler, flags, source_file),
        '```',
    ]
    for l in lines:
        print(l)


if __name__ == '__main__':
    if len(sys.argv) != 4:
        print('Usage: %s <compiler> <flags> <source file>' % sys.argv[0])
        exit(1)
    main(compiler=sys.argv[1], flags=sys.argv[2], source_file=sys.argv[3])
