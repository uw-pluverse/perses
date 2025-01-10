# how to measure memory and time of each cache

## how to measure memory of each cache
Move to the `benchmark` folder
1. Run ``python3 rcc-exp-script/run_benchmarks_parallel.py -n 15 --set all --cache RCCFORMAT --mode memory --repeat 5 --reducer perses;
`` Assume the output folder of Step 1 is ` benchmark_results_perses_RCCFORMAT_all_memory_20240509-09:01:48-969438/`

2. Run ``python3 convert_memory_log_to_csv.py benchmark_results_perses_RCCFORMAT_all_memory_20240509-09:01:48-969438/ -o results.csv``
This will generate a file `results.csv`. Each line summarize the memory usage of one iteration.

3. Run ``python3 rcc-exp-script/analyze_csv_memory.py -i results.csv -o results_MEM.csv``
This new csv file will compute the average of 5 iterations, and the relative ratio w.r.t baseline. This step is optional.

## how to measure memory of each cache

Move to the `benchmark` folder
1. Run ``python3 rcc-exp-script/run_benchmarks_parallel.py -n 15 --set all --cache RCCFORMAT --mode time --repeat 5 --reducer perses;
`` Assume the output folder of Step 1 is ` benchmark_results_perses_RCCFORMAT_all_memory_20240509-09:01:48-969438/`

2. Run ``python3 convert_time_query_to_csv.py -d ~/ssddata/rcc-format/results/benchmark_results_perses_*time* -c``. This command will show message like 'the results will be saved to /ssddata/yqtian/rcc-format/perses-private-figures/benchmark/benchmark_csv/benchmark_csv_20240516-143230_e88054b8b'. The results will be in the .csv file in this folder.
   
3. Run ``python3 rcc-exp-script/analyze_csv_time.py -i results.csv -o results_MEM.csv``
This new csv file will compute the average of 5 iterations, and the relative ratio w.r.t baseline. This step is optional.

Note that, the config of HDD+time is none somehow. In this case, the step 2 should use the command ``python3 convert_time_query_to_csv.py -d ~/ssddata/rcc-format/results/benchmark_results_HDD_*SHA**time* -c``. 

