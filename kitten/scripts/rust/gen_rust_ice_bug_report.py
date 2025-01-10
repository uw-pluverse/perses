#!/usr/bin/env python3

import urllib.request
import sys
import subprocess
import os


def read_remote_ice_template():
    url = 'https://raw.githubusercontent.com/rust-lang/rust/master/.github/ISSUE_TEMPLATE/ice.md'
    with urllib.request.urlopen(url) as f:
        return f.read().decode('utf-8')


def read_source_file(source_file: str) -> str:
    with open(source_file, "r") as f:
        return f.read().strip()


def compute_rustc_version(rustc: str) -> str:
    return subprocess.check_output(
        [rustc, '--version', '--verbose'],
        stderr=subprocess.STDOUT).decode('utf-8').strip()


def run_rustc_to_collect_output(
        rustc: str,
        flags: str,
        source_file: str,
        enable_backtracing: bool = False
) -> str:
    cmd = f'{rustc} {flags} {source_file}'.split()
    env = os.environ.copy()
    if enable_backtracing:
        env['RUST_BACKTRACE'] = '1'
    return subprocess.run(
        cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        env=env).stdout.decode('utf-8').strip()


def main(rustc: str, flags: str, source_file: str):
    template_lines: list[str] = read_remote_ice_template().splitlines()
    for line in template_lines:
        lowered = line.strip().lower()
        if lowered == '<code>':
            print(read_source_file(source_file))
        elif lowered == '<version>':
            print(compute_rustc_version(rustc))
        elif lowered == '<output>':
            print(run_rustc_to_collect_output(rustc, flags, source_file))
        elif lowered == '<backtrace>':
            print(run_rustc_to_collect_output(rustc, flags, source_file, enable_backtracing=True))
        else:
            print(line)


if __name__ == '__main__':
    if len(sys.argv) != 4:
        print('Usage: %s <rustc> <flags> <source file>' % sys.argv[0])
        exit(1)
    main(rustc=sys.argv[1], flags=sys.argv[2], source_file=sys.argv[3])
