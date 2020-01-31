# How to run


## Reduction Programs
The following reduction programs are supported

 - Perses
 - Perses fixpoint mode
 - HDD (WIP)
 - HDD fixpoint mode (WIP)
 - creduce
 - chisel

The run_{reduction program name}.sh files expect a test file, a file to reduce, 
and an optional stat file that the shell script will write the final stat to. 
If the stat file is not provided, the stats will be printed to stdout.

If update_{reduction program name}.sh file is provided, run that to install
the reducer program.


## Token Counter
Counts token. Expect file to count.


## Benchmarking
Run [benchmark.py](https://bitbucket.org/chengniansun/perses/src/master/benchmark/benchmark.py) 
from the benchmark folder.