![](https://github.com/chengniansun/kitten/workflows/CI/badge.svg)

# Kitten: A Simple Yet Effective Baseline for Evaluating LLM-Based Compiler Testing Techniques

**Kitten** is a language-agnostic program generator designed for
evaluating LLM-based compiler testing techniques.
It provides a robust and reproducible baseline for assessing the effectiveness
of LLM-driven compiler testing methods.
By leveraging mutations, Kitten generates diverse test programs that effectively
stress compilers and uncover bugs.

As of February 2025, Kitten has detected over **300 bugs**, many of which have been confirmed. For detailed bug reports, see [here](https://github.com/wxie7/kitten-exp/blob/main/reported-bugs.md).

| Compiler      | GCC | LLVM | Rustc | Solc | JerryScript | scalac | slang |
|--------------|:------:|:-------:|:-----------:|:--------------:|:--------------:|:-------------:|:-------------:|
| Bug Count   | 84     | 100     | 103         | 6              | 8              | 14            | 13            |


This repository contains the source code for **Kitten**, along with installation
and usage instructions.

A demonstration video illustrating its usage is available below:
[![Watch the video](https://img.youtube.com/vi/hVqZBxRTr_4/maxresdefault.jpg)](https://youtu.be/hVqZBxRTr_4)


## Table of Contents
- [Getting Started](#getting-started)
  - [Build From Source](#build-from-source)
  - [Docker Image](#docker-image)
- [Usage](#usage)
  - [Compiler Testing](#compiler-testing)
  - [Bug Management](#bug-management)
  - [Example](#example)
- [Reproducing Experiments](#reproducing-experiments)
  - [Preparation](#preparation)
  - [Testing GCC](#testing-gcc)
  - [Testing LLVM](#testing-llvm)
  - [Testing Rustc](#testing-rustc)

## Getting Started

To use Kitten, we provide both source build and Docker image options.

### Build From Source

To build Kitten from source, follow these steps:
1. Install the required dependencies:
   - [JDK 11](https://openjdk.org/)
   - [Bazel](https://bazel.build/)
2. Clone the Kitten repository (as part of Perses) and compile:
```shell
git clone https://github.com/uw-pluverse/perses.git && cd perses
bazelisk build kitten/src/org/perses/fuzzer:kitten_deploy.jar
bazelisk build kitten/src/org/perses/fuzzer/organizer:kitten_organizer_deploy.jar
cp bazel-bin/kitten/src/org/perses/fuzzer/kitten_deploy.jar .
cp bazel-bin/kitten/src/org/perses/fuzzer/organizer/kitten_organizer_deploy.jar .
```
`kitten_deploy.jar` and `kitten_organizer_deploy.jar` are used for compiler testing execution
and bug management, respectively.

### Docker Image
Alternatively, you can use the pre-built Docker image:
```shell
docker pull kittentool/kitten:v1
```

## Usage
### Compiler Testing
```shell
$ java -jar kitten_deploy.jar --help
Usage: org.perses.fuzzer.Main [options]
  Options:
    --help, -h
      print help message

[Verbosity]  Options:
    --verbosity
      verbosity of logging
      Default: INFO
    --list-verbosity-levels
      list all verbosity levels

[Version]  Options:
    --version
      print the version

[General]  Options:
    --random-seed
      seed for the random number generator.
      Default: 1742132209626
    --seed-limit
      the upper limit of the seed files to be used
      Default: 2147483647
    --interesting-folder
      folder to save interesting mutants
    --finding-folder
      folder to save the findings
    --temp-folder
      folder to save temp files
    --threads
      number of fuzzing threads
      Default: 1
    --timeout
      Time limit for fuzzing (second)
      Default: 0
    --shuffle-seed
      shuffle the seed files
      Default: true
    --language-model
      language model to guide the scheduler. Now only two options are valid:
      ngram and ndepth tree model
      Default: NULL_MODEL
      Possible Values: [NULL_MODEL, N_GRAM_MODEL, N_DEPTH_TREE_MODEL]
    --fuzzer-mode
      the mode to run
      Default: NORMAL_FUZZING
      Possible Values: [ONLY_ON_INITIAL_SEED, ONLY_GENERATE_MUTANTS, NORMAL_FUZZING]
    --mutants-folder
      folder to save generated mutants
    --no-initial-seed
      fuzzing with no initial seed
      Default: false
    --max-seed-pool-size
      the maximum size of seed pool
      Default: 2147483647
    --allow-enable-guidance
      allow to enable guidance, only effective when use n-depth tree model
      Default: true

[Mutation Control]  Options:
    --max-recursions
      The max depth of recursive mutation
      Default: 0
    --generator
      the generator to use. Now only two options are valid: random and guided
      Default: NULL_GENERATOR
      Possible Values: [NULL_GENERATOR, RANDOM_GENERATOR, GUIDED_GENERATOR]
    --enable-replace-with-generated-node
      enable replacing with generated node mutation
      Default: true
    --enable-splicing
      enable splicing mutation
      Default: true
    --enable-deleting-on-random-positions
      enable deleting mutation on random positions
      Default: false
    --enable-deleting-on-continuous-positions
      enable deleting tokens on continuous positions
      Default: false
    --enable-inserting-on-random-positions
      enable inserting mutation on random positions
      Default: false
    --enable-inserting-on-continuous-positions
      enable inserting tokens on continuous positions
      Default: false
    --enable-replacing-on-random-positions
      enable replacing tokens on random positions
      Default: false
    --enable-replacing-on-continuous-positions
      enable replacing tokens on continuous postions
      Default: false
    --enable-replacing-identifier
      enable replacing identifier mutation
      Default: true
    --enable-replacing-same-type-token
      enable replacing same type token mutation
      Default: false
    --enable-deleting-children-of-kleene-node
      enable deleting children of kleene plus/star nodes mutation
      Default: false
    --enable-inserting-children-of-kleene-node
      enable inserting children of kleene plus/star nodes mutation
      Default: false

[Compiler Control]  Options:
  * --testing-config
      an YAML file specifying compilers and seed files

[Coverage]  Options:
    --llvm-path
      an directory that contains llvm binary
    --coverage-info
      an directory that contains gcov information
    --compiler-source
      the directory that contains the source of the target compiler
    --compiler-binary
      the directory that contains the binary of the target compiler
    --coverage-interval
      this parameter controls how frequency the coverage information is
      queried
      Default: 30
    --coverage-save
      the path that the coverage result saved at
    --afl-coverage-mode
      enable afl coverage collection mode, the target should be compiled by
      afl-wrapped compiler
      Default: false
    --gcc-coverage-mode
      enable gcc coverage collection mode, gcc should be compiled with
      '--enable-coverage'
      Default: false
    --rustc-coverage-mode
      enable rustc coverage collection mode
      Default: false
    --llvm-coverage-mode
      enable llvm coverage collection mode
      Default: false
    --llvm-profiles-dir
      the directory that contains llvm profiles
    --coverage-timeout
      Time limit for coverage collection
      Default: 86400

[Language Control]  Options:
    --list-langs
      List all the supported languages.
    --lang
      Specify the language of the program that is to be reduced.
      Default: <empty string>
    --parser-facade-class-name
      The parser facade to be used to parse the input program
      Default: <empty string>
    --list-parser-facades
      List all the available parser facades.
    --language-ext-jars
      A list of JAR files to support new languages
      Default: []
```

### Bug Management
```shell
$ java -jar kitten_organizer_deploy.jar --help
Usage: org.perses.fuzzer.organizer.Main [options]
  Options:
    --help, -h
      print help message
  * --delete-duplicates
      whether to delete the duplicates. If no, duplicates will be saved to the
      duplicate folder.
      Default: true
  * --duplicate-folder
      the folder to store the duplicate bugs
  * --finding-folder
      the folder storing all the found bugs
  * --lang
      language of input file
  * --processing-folder
      the folder to process the found bugs
    --recompute-crash-signatures
      recompute the crash signatures of the found bugs.
      Default: false
  * --reported-folder
      the folder to store the reported bugs

[Verbosity]  Options:
    --verbosity
      verbosity of logging
      Default: INFO
    --list-verbosity-levels
      list all verbosity levels

[Version]  Options:
    --version
      print the version
```
### Example
1. Create a configuration file `config.yaml`, e.g.:
```yaml
language: "C"
seedFolders:
  - path: "seeds"
    fileExtentions: [".c"]

programsUnderTest:
  - command: "gcc"
    flagsToTest:
      - flags: ["-x", "c", "-std=c2x", "-c"]
    versionFlags:
      flags: ["-v"]
    crashDetectorClassName: "org.perses.fuzzer.compilers.c.GccCrashDetector"
```
2. Put some seeds in `seeds` folder.
3. Run Kitten:
```
java -jar kitten_deploy.jar --testing-config config.yaml \
  --timeout 3600 \
  --max-recursions 5 \
  --enable-splicing true \
  --fuzzer-mode NORMAL_FUZZING \
  --verbosity "INFO"
```
After execution, the detected bugs are located in the directory specified by the
`--finding-folder` parameter. If this parameter is not specified, the default
directory is `default_finding_folder`.

We can then use the bug management feature to deduplicate the detected bugs with the following command:

```sh
java -jar kitten_organizer_deploy.jar --lang C \
  --finding-folder default_finding_folder \
  --duplicate-folder default_duplicate_folder \
  --processing-folder default_processing_folder \
  --reported-folder default_reported_folder \
  --delete-duplicates true
```

## Reproducing Experiments
To reproduce the results from the paper, you can use the scripts in
[kitten-exp](https://github.com/wxie7/kitten-exp) to install GCC, LLVM, and
Rustc. Alternatively, you can use the pre-packaged Docker image, which includes
a version of GCC with coverage collection support. However, due to the large
file size of LLVM and Rustc with coverage support, the LLVM and Rustc included
in the Docker image do not support coverage collection by default. To enable
coverage collection for LLVM and Rustc, you need to recompile them using the
scripts provided in [kitten-exp](https://github.com/wxie7/kitten-exp).

### Preparation
Option 1: Configure the three compilers and prepare the seed set using the
scripts in `kitten-exp`.

Option 2: Use the provided Docker image `kittentool/kitten:v1`.

### Testing GCC
Run the following command to test GCC:

```shell
bash kitten/gcc/fullrun.sh
```
The detected bugs will be located in `kitten/gcc/fullrun/default_finding_folder`, with a structure similar to the following:

```shell
├── crash_20250313_144455_0052
│   ├── bug_descriptor.properties
│   ├── crash_signature.txt
│   ├── delta
│   ├── mutant.c
│   ├── reproduce.sh
│   ├── seed.c
│   ├── stderr.txt
│   └── stdout.txt
└── crash_20250313_144919_0053
    ├── bug_descriptor.properties
    ├── crash_signature.txt
    ├── delta
    ├── mutant.c
    ├── reproduce.sh
    ├── seed.c
    ├── stderr.txt
    └── stdout.txt
```
The `mutant.c` file is the test case that triggers the bug, and `reproduce.sh` is a script to reproduce the bug.

To collect coverage data, navigate to the `kitten/gcc/fullrun/coverage` directory and run:

```shell
python3 /kitten-exp/kitten/merge_coverage_to_csv.py 1 24 lines.csv
```

### Testing LLVM
The command for testing LLVM is similar to testing GCC. Run:

```bash
bash kitten/llvm/fullrun.sh
```
To collect coverage data, you need to enable
`-DLLVM_BUILD_INSTRUMENTED_COVERAGE=ON` when compiling LLVM.

### Testing Rustc
Testing Rustc is also similar. Run:

```shell
bash kitten/rustc/fullrun.sh
```
To collect coverage data, modifications to Rustc's source code are required. See:
- [kitten-exp script (Line 38)](https://github.com/wxie7/kitten-exp/blob/main/rustc/install_rustc.sh#L38)
- [Stack Overflow discussion](https://stackoverflow.com/questions/79112200/how-to-collect-code-coverage-for-the-rustc-compiler-itself)

The `kitten-exp` scripts have coverage support enabled by default.