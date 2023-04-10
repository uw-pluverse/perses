### Git Workflow ###

* Please use `git rebase` rather than `git merge` to manage your git workflow.
* Please run `./scripts/install_hooks.sh` right after you clone this repository.

### Build and Test ###

Perses is written in combination of Java 11 and Kotlin, and built with [Bazel](https://bazel.build/). 

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

For more instructions on the benchmark folder, please refer to this [document](https://github.com/perses-project/perses/tree/master/benchmark)

### For Intellij Users ###

You can use the [Bazel plugin for Intellij](https://plugins.jetbrains.com/plugin/8609-bazel/) to import the project into Ideas, 
and then run/debug as usual. You can find more at [the official documentation](https://ij.bazel.build/docs/bazel-plugin.html)