# Perses: Syntax-Directed Program Reduction#

Perses is a language-agnostic program reducer to minimize a program with 
respect to a set of constraints. It takes as input a program to reduce,
and a test script which specifies the constraints.
It outputs a minimized program which still satisfies the constraints specified
in the test script. Compared to Delta Debugging and Hierarchical Delta Debugging,
Perses leverages the syntax information in the Antlr grammar, and prunes the
search space by avoiding generating syntactically invalid programs.


### Build & Use ###

```shell
git clone https://github.com/chengniansun/perses.git
cd perses
bazel build //src/org/perses:perses_deploy.jar
```

Bazel will generate a self-contained java file named *perses_deploy.jar*.
This jar file includes all required class files, and can be directly run
with the following command.

```shell
java -jar perses_deploy.jar  [options]? --test-script <test-script.sh> --input-file <program file>
```

* __test-script.sh__:
The script encodes the constraints that the original program file and the reduced version should satisfy. It should return **0** if the constraints are satisfied. 
 
* __program file__: the program needs to be reduced. Currently, antlr-hdd 
supports the following languages, C, Java. Note that we can easily support any other languages, if the specific language can be parsed by an Antlr parser. 



Check all available command line arguments

```shell
java -jar perses_deploy.jar  --help
```


### For Developers ###

Perses is written in Java 8, and built with [Bazel](https://bazel.build/). 

To build, run

```
bazel build antlropt/... src/... test/...
```

To test, run

```
bazel test test/...
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

In the docker container, you can build the benchmark and run the tests with the following

```shell
cd perses
bazel test benchmark/...
```

#### For Intellij Users ####

You can use the [Bazel plugin for Intellij](https://plugins.jetbrains.com/plugin/8609-bazel/) to import the project into Ideas, 
and then run/debug as usual. You can find more at [the official documentation](https://ij.bazel.build/docs/bazel-plugin.html)

### License ###
GNU General Public License 3.