# RCC

This documents details how to reproduce the results in our manuscript **On the Caching Schemes to Speed Up Program Reduction**

If you have any question, feel free to create an issue in this repo.

## Implementation

The RCC, i.e., Refreshable Compact Caching, is integrated in [Perses](https://github.com/uw-pluverse/perses).
To understand its implementation, we suggest starting it from [here](../src/org/perses/reduction/cache/CompactQueryCache.kt).

Similarly, other caching schemes are also available at [here](../src/org/perses/reduction/cache),
such as [ZIP](../src/org/perses/reduction/cache/ContentSHA512BasedQueryCache.kt),
[SHA](../src/org/perses/reduction/cache/ContentZipBasedQueryCache.kt),
and 
[STR](../src/org/perses/reduction/cache/ContentStringBasedQueryCache.kt).


## Reproduction

### Requirement

#### Software
1. docker: the experiments need to be executed in docker since some property tests require specific gcc/clang versions.
2. OS: we use Ubuntu20.04 in our study. Other linux distributions should also work.

#### Hardware
1. x86 machine: we test it in Intel and AMD machine and both work well. 
2. To run all experiments, 128 GB ram is recommended.


### Preparation

1. Clone the Perses repo:
```bash
git clone https://github.com/uw-pluverse/perses
```

2. Start the docker
```bash
cd perses/benchmark
./start_docker.sh
cd perses/benchmark
./init_docker.sh
```

3. Build Perses (in docker) (~20 mins)
```bash
./binaries/update_perses.sh
```

4. Run the experiments (in docker)


### Time

```bash
./run_benchmark.py
```

Run `./benchmark.py --help` for a list of all the arguments.

For example, to measure the runtime of Perses with RCC on subject gcc-70586, we use the following command

```bash
JVM_FLAGS="-Xmx128g -da" PERSES_FLAGS="--query-cache-type COMPACT_QUERY_CACHE" python3 run_benchmark.py --subjects clang-22382 --reducers perses -ss --iterations 1 -o benchmark_results_perses_RCC_time > clang-22382_rcc_time.log 2>&1 &;
```

The .json file in folder `benchmark_results_perses_RCC_time` lists the result.
```json
{
    "Subject": "clang-22382",
    "Reducer": "perses",
    "Environment": "--query-cache-type COMPACT_QUERY_CACHE",
    "Origin token count": 21068,
    "Iteration": 0,
    "Query": 2381,
    "Time": 232,
    "Token_remaining": 144,
    "Ret_code": 0
}
```

### Memory

```bash
./run_cache_profiling.py
```

Run `./run_cache_profiling.py --help` for a list of all the arguments.

For example, in our study, to measure the cache size of SHA/ZIP/RCC of Perses on subject clang-22382, we use the following command

```bash
JVM_FLAGS="-Xmx128g -da" PERSES_FLAGS="--query-cache-type COMPACT_QUERY_CACHE" python3 run_cache_profiling.py --subjects clang-22382 --reducers perses -ss --iterations 1 -o benchmark_results_perses_RCC_memory --monitor-interval 100000 > clang-22382_rcc_memory.log 2>&1 &;
```

The .log file in folder `benchmark_results_perses_RCC_time` lists the result.
The first column is the timestamp (Java) and the second column is the cache size in Byte. 
Please note that the exact value will be different in different hardware.

```
1680896469730 392
1680896569747 2472
1680896669830 2216
1680896716037 34280
```

### Other flags

#### Use other cache scheme
To use SHA/ZIP/STR, change the `PERSES_FLAGS="--query-cache-type COMPACT_QUERY_CACHE"` to
`PERSES_FLAGS="--query-cache-type CONTENT_SHA512"`,
`PERSES_FLAGS="--query-cache-type CONTENT_ZIP"`,
and `PERSES_FLAGS="--query-cache-type ORIG_CONTENT_STRING_BASED"`, respectively.

#### Disable cache
To disable cache, change `PERSES_FLAGS="--query-cache-type COMPACT_QUERY_CACHE"` in the above commands to `--edit-caching false --query-caching false`.

#### Use HDD
To use HDD instead of Perses, change `--reducers perses` in the above commands to `--reducers hdd`.




