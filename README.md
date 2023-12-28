![CI](https://github.com/uw-pluverse/perses/actions/workflows/main.yml/badge.svg)

# Perses: Syntax-Directed Program Reduction

Perses is a language-agnostic program reducer to minimize a program with
respect to a set of constraints. It takes as input a program to reduce,
and a test script which specifies the constraints.
It outputs a minimized program which still satisfies the constraints specified
in the test script. Compared to Delta Debugging and Hierarchical Delta Debugging,
Perses leverages the syntax information in the Antlr grammar, and prunes the
search space by avoiding generating syntactically invalid programs.

### Supported Languages

Currently, Perses supports reduction for the following programming languages:

+ C: [c]
+ Cpp: [cc, cpp, cxx]
+ Rust: [rs]
+ Scala: [scala, sc]
+ Java: [java]
+ JavaScript: [javascript, js]
+ Python3: [py, py3]
+ GLSL: [glsl, comp, frag, vert]
+ Go: [go]
+ PHP: [php]
+ Ruby: [rb]
+ SQLite: [sqlite]
+ MySQL: [mysql]
+ Solidity: [sol]
+ System_Verilog: [v, sv]
+ SMTLIBv2: [smt2]

Support for other languages is coming soon.

### Obtain and Run

There are three ways to obtain Perses.

- Download a prebuilt release JAR file from our [release page](https://github.com/perses-project/perses/releases),
  for example,

      ```
      wget https://github.com/perses-project/perses/releases/download/v1.4/perses_deploy.jar
      java -jar perses_deploy.jar [options]? --test-script <test-script.sh> --input-file <program file>
      ```

- Clone the repo and build Perses from the source.

  ```
  git clone https://github.com/perses-project/perses.git
  cd perses
  bazel build //src/org/perses:perses_deploy.jar
  java -jar bazel-bin/src/org/perses/perses_deploy.jar [options]? --test-script <test-script.sh> --input-file <program file>
  ```

- If you want to always use the trunk version of Perses, [perses-trunk](https://github.com/perses-project/perses/blob/master/scripts/perses-trunk) automatically downloads and builds the latest version.
  NOTE: [Bazel](https://bazel.build/) is the prerequisite to run perses-trunk successfully.
  `  wget https://raw.githubusercontent.com/perses-project/perses/master/scripts/perses-trunk
chmod +x perses-trunk
./perses-trunk [options]? --test-script <test-script.sh> --input-file <program file>`

#### Important Flags

- --test-script **<test-script.sh>**:
  The script encodes the constraints that both of the original program file and the reduced version should satisfy. It should return **0** if the constraints are satisfied.

- --input-file **<program-file>**: the program needs to be reduced. Currently, Perses
  supports C, Rust, Java and Go. Note that we can easily support any other languages,
  if the specific language can be parsed by an Antlr parser.

Check all available command line arguments

```
java -jar perses_deploy.jar  --help
```

### License

GNU General Public License 3.

### References

This repository contains the implementations of the techniques proposed in the following papers. 

#### 1. Perses: Syntax-Guided Program Reduction (ICSE 2018, [pdf](./doc/publication/2018_perses_icse.pdf))

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

##### 2. Pushing the Limit of 1-Minimality of Language-Agnostic Program Reduction (OOPSLA 2023, [pdf](./doc/publication/2023_vulcan_oopsla.pdf))

```
@article{vulcan,
  title={Pushing the Limit of 1-Minimality of Language-Agnostic Program Reduction},
  author={Xu, Zhenyang and Tian, Yongqiang and Zhang, Mengxiao and Zhao, Gaosen and Jiang, Yu and Sun, Chengnian},
  journal={Proceedings of the ACM on Programming Languages},
  volume={7},
  number={OOPSLA1},
  pages={636--664},
  year={2023},
  publisher={ACM New York, NY, USA}
}
```

##### 3. PPR: Pairwise Program Reduction (ESEC/FSE 2023, [pdf](./doc/publication/2023_ppr_fse.pdf))

```
@inproceedings{ppr,
  title={PPR: Pairwise Program Reduction},
  author={Zhang, Mengxiao and Xu, Zhenyang and Tian, Yongqiang and Jiang, Yu and Sun, Chengnian},
  booktitle={Proceedings of the 31st ACM Joint European Software Engineering Conference and Symposium on the Foundations of Software Engineering},
  pages={338--349},
  year={2023}
}
```

##### 4. On the Caching Schemes to Speed Up Program Reduction (TOSEM, [pdf](./doc/publication/2023_caching_tosem.pdf))

```
@article{perses-caching,
  title={On the Caching Schemes to Speed Up Program Reduction},
  author={Tian, Yongqiang and Zhang, Xueyan and Dong, Yiwen and Xu, Zhenyang and Zhang, Mengxiao and Jiang, Yu and Cheung, Shing-Chi and Sun, Chengnian},
  journal={ACM Transactions on Software Engineering and Methodology},
  volume={33},
  number={1},
  pages={1--30},
  year={2023},
  publisher={ACM New York, NY, USA}
}
```
