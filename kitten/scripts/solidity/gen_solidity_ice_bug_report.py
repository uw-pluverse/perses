#!/usr/bin/env python3

import urllib.request
import sys
import subprocess
import os


def read_remote_ice_template() -> str:
    url = 'https://raw.githubusercontent.com/ethereum/solidity/develop/.github/ISSUE_TEMPLATE/bug_report.md'
    with urllib.request.urlopen(url) as f:
        return f.read().decode('utf-8')


def read_source_file(source_file: str) -> str:
    with open(source_file, "r") as f:
        return f.read().strip()


def compute_solc_version(solc: str) -> str:
    return subprocess.check_output(
        [solc, '--version'],
        stderr=subprocess.STDOUT).decode('utf-8').strip().splitlines()[-1]


def run_solc_to_collect_output(
        solc: str,
        flags: str,
        source_file: str
) -> str:
    cmd = f'{solc} {flags} {source_file}'.split()
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


def main(solc: str, flags: str, source_file: str):
    template_lines: list[str] = read_remote_ice_template().splitlines()
    for line in template_lines:
        lowered = line.strip().lower()
        if "compiler version:" in lowered:
            print(f'{line} {compute_solc_version(solc)}')
        elif "operating system:" in lowered:
            print(f'{line} {get_system_information()}')
        else:
            print(line)
    dummy_source_file = 'small.sol'

    print(f'#### Test program: {dummy_source_file}')
    print('```solidity')
    print(read_source_file(source_file))
    print('```')

    print('#### Compiler Command')
    print('```bash')
    print(f'{solc} {" ".join(flags)} {dummy_source_file}')
    print('```')

    print('#### Output')
    print('```')
    print(run_solc_to_collect_output(solc, flags, source_file))
    print('```')


if __name__ == '__main__':
    if len(sys.argv) != 4:
        print('Usage: %s <solc> <flags> <source file>' % sys.argv[0])
        exit(1)
    main(solc=sys.argv[1], flags=sys.argv[2], source_file=sys.argv[3])
