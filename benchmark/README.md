# Files in this directory

## benchmark.py

Runs the benchmark 

### How to run

```shell
git clone https://github.com/chengniansun/perses.git
cd perses/benchmark
./start_docker.sh
cd perses/benchmark
./init_docker.sh
```
In the docker container, running benchmark.py will build and install different reducers and run reductions 
```shell
./benchmark.py
```

### Arguments
Run ```./benchmark.py --help``` for a list of all the arguments

#### --subjects
Run benchmark(s) on specified bench(es). 
```
--subjects clang-27137 gcc-59903
```

#### --iterations
Run benchmark(s) on each bench for specified number of times before switching to the next.

#### --silent
Write no results to stdout and save no json file.

#### --show-subprocess
Display all pipe stdout and stderr from reducers. Details of the reduction process will be dislayed.

#### --reducers
Specify reducer(s) to benchmark. 
```
--reducers perses hdd creduce
```

#### --list-reducers
List current available reducers.

#### --memory-profiler
Enable Perses memory usage profiler and output runtime data to a text file.

### Supported Reducers
Currently the reducers are ran in the following order
* Perses
* HDD
* Perses Fixed point
* HDD Fix point
* CReduce
* Chisel

### Environment Variables
Perses allows additional environment variables for testing flexibilities.

### PERSES_EXTRA_FLAGS
Provide additional command line arguments to Perses. If not specified, Perses would run default settings.
```
PERSES_EXTRA_FLAGS="--query-caching false --edit-caching false" ./benchmark.py ...
```

