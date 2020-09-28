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

#### --subjects
Run benchmark(s) on specified bench(es). E.g. ```--subjects clang-27137 gcc-59903```

#### --iterations
Run benchmark(s) on each bench for specified number of times before switching to the next.

#### --silent
Write nothing to stdout and save no test results.

#### --show-subprocess
Display all pipe stdout and stderr from reducers. Details of the reduction process will be dislayed.



### Supported Reducers
Currently the reducers are ran in the following order
* Perses
* HDD
* Perses Fixed point
* HDD Fix point
* CReduce
* Chisel
