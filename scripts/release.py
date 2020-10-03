#!/usr/bin/env python3

import os
import subprocess


def create_tag():
    subprocess.check_call(["git", "fetch", "--all", "--tags"]) # fetch remote tags
    # create new tag as per current release
    stream = os.popen('git describe --abbrev=0 --tags')
    current_tag = stream.read().strip()
    # TODO(Xueyan): the current parsing is buggy, if the main version number is a two-digit number.
    #      You need parse the string, e.g., the first string is 'v', and after 'v', there should be
    #      two numbers seperated by a '.'
    if current_tag[0] != 'v':
        raise Exception("The tag name should start with v")
    major_version = int(current_tag[1])
    minor_version = int(current_tag[3])
    q, r = divmod(minor_version + 1, 10)
    return "v{}.{}".format(major_version + q, r)


def build_binary():
    # return built binary location
    print("building binary...")
    build_command = ['bazel', 'build', '//src/org/perses:perses_deploy.jar']

    pipe = None
    subprocess.check_call(
        build_command,
        stdout=pipe,
        stderr=pipe)
    # assume constant build path
    return "bazel-bin/src/org/perses/perses_deploy.jar"


def main():
    # ensure in root folder
    if not os.path.exists("WORKSPACE"):
        raise Exception('ERROR: This script should be run in the root folder of the project.')

    tag_name = create_tag()
    title = "Perses {}".format(tag_name)

    # get built binary path
    jar = build_binary()

    # release
    release_command = ['hub', 'release', 'create', '-a', jar, '-m', title, tag_name]

    pipe = None
    subprocess.check_call(
        release_command,
        stdout=pipe,
        stderr=pipe)


if __name__ == "__main__":
    main()
