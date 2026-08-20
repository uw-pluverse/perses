# Differential Analysis Visualization Tool

This tool provides a graphical interface to compare the reduction progress of
two different `Perses` runs. It is designed to help developers debug the
performance of different reduction algorithms or configurations by visualizing
which edits were successful and how they affected the program size over time.

## Purpose

The differential analyzer allows you to:
- Visualize the tree of reduction events for two different runs side-by-side.
- Identify "interesting" edits (edits that successfully reduced the program
  while preserving the property of interest).
- Compare the efficiency of different reduction strategies.
- Inspect the code that was deleted during specific reduction steps.

## Data Collection

Before using this tool, you must collect reduction progress data from two
separate Perses runs.

1. Run Perses with the following flag to enable the differential analysis
   profiler:
   ```bash
   --profile-for-reduction-progress-differential-analysis <output_path.yaml>
   ```
2. Perform this for two different runs (e.g., Run A and Run B) to generate two
   YAML files:
   - `run_a_progress.yaml`
   - `run_b_progress.yaml`

## Build Instructions

To build the visualization tool using Bazel, run:

```bash
bazelisk build //src/org/perses/analyzer/differential:Main
```

## Running Instructions

### Method 1: Using Bazel

To start the visualization tool and compare two runs using Bazel, use the
following command:

```bash
bazelisk run //src/org/perses/analyzer/differential:Main -- <path_to_run_a.yaml> <path_to_run_b.yaml>
```

### Method 2: Using the Standalone Deploy JAR

If you prefer to run the tool without using Bazel directly (e.g., in an
environment where Bazel is not installed but the JVM is available), you can
build and use a standalone "deploy" JAR:

1. Build the deploy JAR:
   ```bash
   bazelisk build //src/org/perses/analyzer/differential:Main_deploy.jar
   ```

2. Run the tool using `java -jar`:
   ```bash
   java -jar bazel-bin/src/org/perses/analyzer/differential/Main_deploy.jar <path_to_run_a.yaml> <path_to_run_b.yaml>
   ```

Replace `<path_to_run_a.yaml>` and `<path_to_run_b.yaml>` with the absolute or
relative paths to the YAML files you collected during the data collection step.
