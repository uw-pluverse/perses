# Files in this directory

## benchmark.py

Runs the benchmark 

### How to run

```shell
git clone https://github.com/chengniansun/perses.git
cd perses/benchmark
./start_docker.sh
```
In the docker container, running benchmark.py will build and install different reducers and run reductions
```shell
cd perses/benchmark
./benchmark.py
```

### Arguments
Run ```./benchmark.py --help``` for a list of all the arguments

#### --benchmark-subset
Runs the following set of benchmarks in order. Takes about 3 minuets on an i7-6770HQ

| Index | Benchmarks  |
|------:|-------------|
|     0 | toys/parentheses |
|     1 | toys/delta_1 |

#### --benchmark-all
Runs the following set of benchmarks in order

| Index | Benchmarks  |
|------:|-------------|
|     0 | clang-22382 |
|     1 | clang-22704 |
|     2 | clang-23309 |
|     3 | clang-23353 |
|     4 | clang-25900 |
|     5 | clang-26350 |
|     6 | clang-26760 |
|     7 | clang-27137 |
|     8 | clang-27747 |
|     9 | clang-31259 |
|    10 | gcc-59903   |
|    11 | gcc-60116   |
|    12 | gcc-61383   |
|    13 | gcc-61917   |
|    14 | gcc-64990   |
|    15 | gcc-65383   |
|    16 | gcc-66186   |
|    17 | gcc-66375   |
|    18 | gcc-70127   |
|    19 | gcc-70586   |
|    20 | gcc-71626   |

#### --silent
Writes nothing to stdout

#### --silent-subprocess
Do not pipe the stdout and stderr from the reducers to the benchmark script. Useful if you only want results

#### --output OUTPUT
File where results from the benchmarks are dumped.

#### --start START
Starting index from the list of benchmarks where the benchmark process begins.

* ex. If you want to benchmark with only gcc run ```./benchmark.py --benchmark-all --start 10```

#### --length LENGTH
Number of benchmarks from the list to run.

* ex. If you want to benchmark only gcc-59903 run ```./benchmark.py --benchmark-all --start 10 --length 1```


### Supported Reducers
Currently the reducers are ran in the following order
* Perses
* HDD
* Perses Fixed point
* HDD Fix point
* CReduce
* Chisel