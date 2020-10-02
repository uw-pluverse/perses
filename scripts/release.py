#!/usr/bin/env python3

import os
import subprocess

def create_tag():
    # create new tag as per current release
    stream = os.popen('git describe --abbrev=0 --tags')
    current_tag = float(stream.read().strip()[1::])
    return "v{:.1f}".format(current_tag+0.1)

def build_binary():
    # return built binary location
    print("building binary...")
    build_command = "bazel build //src/org/perses:perses_deploy.jar".split()
    
    pipe = None
    output = subprocess.run(
            build_command, 
            stdout=pipe,
            stderr=pipe)
    # assume constant build path
    return "./bazel-bin/src/org/perses/perses_deploy.jar"


def main():

    # ensure in root folder
    if not os.path.exists("./WORKSPACE"):
        raise Exception('ERROR: This script should be run in the root folder of the project.')

    tag_name = create_tag()

    # get built binary path
    jar = build_binary()

    # release
    release_command = "hub release create -a {} {}".format(jar, tag_name).split()
    print(release_command)
    
    pipe = None
    subprocess.run(
            release_command,
            stdout=pipe,
            stderr=pipe)

if __name__ == "__main__":
    main()
