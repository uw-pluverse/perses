# Benchmark Utility

## run_benchmark.py

A tool to benchmark multiple benchmark subjects with multiple reducers,
and save the result (json format) to `benchmark_results` folder, 
including performance metrics:
#queries, runtime, #tokens before/after reduction.


### How to run

```shell
git clone https://github.com/chengniansun/perses.git
cd perses/benchmark
./start_docker.sh
cd perses/benchmark
./init_docker.sh
```
Note:
Ensure the `bazel --version` does not output `0.29.1`.  
If it does, then `bazel` is not properly installed.  
Try to trace the stdout for error messages.


In the docker container, running `benchmark.py` will automatically build and install different reducers and run reductions 
```shell
./run_benchmark.py [args]
```

Note: To avoid conflicts on resources, do not use Bazel to compile the project 
in both host and virtual machine simultaneously. 

### Arguments
Run ```./benchmark.py --help``` for a list of all the arguments

#### --subjects
Run benchmark(s) on specified subject(s). 
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

##### JVM_FLAGS
Users can pass in JVM options with `JVM_FLAGS` env variable.  
Example of setting max heap size,
```
JVM_FLAGS="-Xmx32G" ./benchmark.py ...
```

##### PERSES_FLAGS
Provide additional command line arguments to Perses. If not specified, Perses would run default settings.  
Example of disabling caching.
```
PERSES_FLAGS="--query-caching false --edit-caching false" ./benchmark.py ...
```

Note: Both environment variables can be set at the same time.
```
JVM_FLAGS="..." PERSES_FLAGS="..." ./benchmark.py ...
```

## convert_result_to_csv.py
A tool to convert benchmarking results to `.csv` file for further analysis.
### How to run
```shell
./convert_result_to_csv.py [args]
```
### Arguments
#### --input-directory INPUT_DIRECTORY
Input directory containing the benchmark results in the type of '*.json'.
#### --output-flag OUTPUT_FLAG
Extra flag to append to output csv file name for distinguishing purposes.


More details see `./convert_result_to_csv.py --help`j
