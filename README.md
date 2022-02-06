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
+ System Verilog

Support for other languages is comming soon. 

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

+ If you want to always use the trunk version of Perses, [perses-trunk](https://github.com/perses-project/perses/blob/master/scripts/perses-trunk) automatically downloads and builds the latest version.
NOTE: [Bazel](https://bazel.build/) is the prerequisite to run perses-trunk successfully.
    ```
    wget https://raw.githubusercontent.com/perses-project/perses/master/scripts/perses-trunk
    chmod +x perses-trunk
    ./perses-trunk [options]? --test-script <test-script.sh> --input-file <program file>
    ```

#### Important Flags ####
* --test-script __<test-script.sh>__:
The script encodes the constraints that both of the original program file and the reduced version should satisfy. It should return **0** if the constraints are satisfied. 
 
* --input-file __<program-file>__: the program needs to be reduced. Currently, Perses 
supports C, Rust, Java and Go. Note that we can easily support any other languages,
if the specific language can be parsed by an Antlr parser. 



Check all available command line arguments

```
java -jar perses_deploy.jar  --help
```

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
