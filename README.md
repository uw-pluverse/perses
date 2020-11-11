# Perses: Syntax-Directed Program Reduction

Perses is a language-agnostic program reducer to minimize a program with 
respect to a set of constraints. It takes as input a program to reduce,
and a test script which specifies the constraints.
It outputs a minimized program which still satisfies the constraints specified
in the test script. Compared to Delta Debugging and Hierarchical Delta Debugging,
Perses leverages the syntax information in the Antlr grammar, and prunes the
search space by avoiding generating syntactically invalid programs.

### Supported Languages ###

Currently, Perses supports reduction for the following programming languages:

+ C
+ Rust
+ Java 8
+ Go

Support for other languages is planned or under development, and will happen soon. 

### Obtain and Run ###

There are three ways to obtain Perses.

+  Download a prebuilt release JAR file from our [release page](https://github.com/perses-project/perses/releases),
for example,
    
    ```
    wget https://github.com/perses-project/perses/releases/download/v1.4/perses_deploy.jar
    java -jar perses_deploy.jar [options]? --test-script <test-script.sh> --input-file <program file>
    ```

+ Clone the repo and build Perses from the source.

    ```
    git clone https://github.com/perses-project/perses.git
    cd perses
    bazel build //src/org/perses:perses_deploy.jar
   java -jar bazel-bin/src/org/perses/perses_deploy.jar [options]? --test-script <test-script.sh> --input-file <program file>
    ```

+ If you want to always use the trunk version of Perses, you can use [perses-trunk](https://github.com/perses-project/perses/blob/master/scripts/perses-trunk).
It can be installed on your machine with

    ```
    wget https://raw.githubusercontent.com/perses-project/perses/master/scripts/perses-trunk
    chmod +x perses-trunk
    # mv perses-trunk to your $PATH
    perses-trunk [options]? --test-script <test-script.sh> --input-file <program file>
    ```

#### Important Flags ####
* --test-script __<test-script.sh>__:
The script encodes the constraints that the original program file and the reduced version should satisfy. It should return **0** if the constraints are satisfied. 
 
* --input-file __<program file>__: the program needs to be reduced. Currently, Perses 
supports C, Rust, Java and Go. Note that we can easily support any other languages,
if the specific language can be parsed by an Antlr parser. 



Check all available command line arguments

```
java -jar perses_deploy.jar  --help
```


### For Developers ###

Perses is written in combination of Java 8 and Kotlin, and built with [Bazel](https://bazel.build/). 

To build, run

```
bazel build //src/org/perses:perses_deploy.jar 
```

To test, run

```
./scripts/presubmit.sh
```

Note that, if you just want to run all the tests, you do not need to run the build command first.
Bazel will run it before the test command automatically for you.

##### Run the tests in the benchmark folder #####

The tests in the benchmark require an extensive list of prerequisites.
We have provided a docker image to set up the testing environment. To start
the docker container, run

```shell
cd benchmark
./start_docker.sh
``` 

For more instructions on the benchmark folder, pelase refer to this [document](https://github.com/perses-project/perses/tree/master/benchmark)

#### For Intellij Users ####

You can use the [Bazel plugin for Intellij](https://plugins.jetbrains.com/plugin/8609-bazel/) to import the project into Ideas, 
and then run/debug as usual. You can find more at [the official documentation](https://ij.bazel.build/docs/bazel-plugin.html)

### License ###
GNU General Public License 3.

### Reference ###
Perse was first published at *International Conference on Software Engineering 2018* as a [full research paper](https://dl.acm.org/doi/10.1145/3180155.3180236).
```
@inproceedings{perses,
  author = {Sun, Chengnian and Li, Yuanbo and Zhang, Qirun and Gu, Tianxiao and Su, Zhendong},
  title = {Perses: Syntax-Guided Program Reduction},
  year = {2018},
  publisher = {Association for Computing Machinery},
  doi = {10.1145/3180155.3180236},
  booktitle = {Proceedings of the 40th International Conference on Software Engineering},
  pages = {361–371},
}
```
