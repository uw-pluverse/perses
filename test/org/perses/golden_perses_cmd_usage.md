# Command Line Arguments

```
Usage: org.perses.Main [options]
```

## Outputs

| Flag | Description | Default |
| --- | --- | --- |
| `--output-dir`, `-o` | The output directory to save the reduced result. |  |

## Inputs

| Flag | Description | Default |
| --- | --- | --- |
| `--test-script`, `--test`, `-t` | **Required.** The test script to specify the property the reducer needs to preserve. |  |
| `--input-file`, `--input`, `-i` | **Required.** The input file(s) or directory(ies) to reduce. Repeat the flag to pass multiple, e.g. --input a.c --input b.c, or --input src\_dir. A directory is expanded recursively to all regular files under it (the test script and any --deps files are excluded). | `[]` |
| `--deps` | The dependency file(s) or directory(ies) required for running the property test. A directory is expanded recursively to all regular files under it. | `[]` |

## General Reduction Control

| Flag | Description | Default |
| --- | --- | --- |
| `--global-fixpoint` | iterative reduction till fixpoint, globally | `false` |
| `--fixpoint` | iterative reduction till fixpoint, for the main reducer only | `true` |
| `--threads` | Number of reduction threads: a positive integer, or 'auto'. | `auto` |
| `--code-format` | The format of the reduced program.<br>Possible values: `SINGLE_TOKEN_PER_LINE`, `ORIG_FORMAT`, `COMPACT_ORIG_FORMAT`, `PYTHON3_FORMAT`, `COMPACT_PYTHON3_FORMAT`, `YAML_FORMAT` |  |
| `--script-execution-timeout-in-seconds` | the interval in seconds to timeout the test script executions. the default timeout is 600 seconds. | `600` |
| `--script-execution-keep-waiting-after-timeout` | keep trying even after the script execution timeouts. | `true` |

## Output Refining Control

| Flag | Description | Default |
| --- | --- | --- |
| `--call-formatter` | call a formatter on the final result | `false` |
| `--format-cmd` | the command to format the reduced source file | *empty string* |
| `--call-creduce` | call C-Reduce when Perses is done. | `false` |
| `--creduce-cmd` | the C-Reduce command name or path | `creduce` |

## Reduction Algorithm Control

| Flag | Description | Default |
| --- | --- | --- |
| `--alg` | The main reduction algorithm: use --list-algs to list all available algorithms |  |
| `--cleanup-alg` | The cleanup reduction algorithm, which is the non-first reduction algorithm used in the fixpoint iteration. Use --list-algs to list all available algorithms. |  |
| `--list-algs` | list all the reduction algorithms. |  |
| `--list-list-minimizers` | list all the list minimizers, one per line. |  |
| `--reparse-each-iteration` | Reparse the program before the start of each fixpoint iteration. | `true` |
| `--enable-token-slicer` | Enable token slicer after syntax-guided reduction is done. Maybe slow. | `false` |
| `--enable-tree-slicer` | Enable tree slicer after syntax-guided reduction, and before token slicer | `false` |
| `--line-slicer` | whether to run the line slicer (after syntax-guided reduction, before the token slicer): auto (only for files that do not parse under their real grammar), on (every file), or off<br>Possible values: `AUTO`, `ON`, `OFF` | `AUTO` |
| `--min-slicing-window-size` | The minimum window size of the windowed slicer. | `1` |
| `--max-slicing-window-size` | The maximum window size of the windowed slicer. | `14` |

## Language Control

| Flag | Description | Default |
| --- | --- | --- |
| `--list-langs` | List all the supported languages. |  |
| `--lang` | Specify the language of the program that is to be reduced. | *empty string* |
| `--parser-facade-class-name` | The parser facade to be used to parse the input program | *empty string* |
| `--list-parser-facades` | List all the available parser facades. |  |
| `--language-ext-jars` | A list of JAR files to support new languages | `[]` |

## Classical Perses Reducer Control

| Flag | Description | Default |
| --- | --- | --- |
| `--default-list-minimizer-for-kleene` | The default list minimizer algorithm to reduce kleene nodes.<br>Possible values: `PRISTINE_DDMIN`, `PERSES_VARIANT_OF_PRISTINE`, `DFS`, `BFS`, `CDD`, `WEIGHTED_DFS`, `WEIGHTED_BFS`, `PROBDD`, `WDD`, `WPROBDD`, `WINDOWED_SLICER`, `LOCAL_EXHAUSTIVE_PATTERN_ENUMERATION`, `ONE_BY_ONE`, `ADAPTIVE_GAIN_DRIVEN`, `DRDD`, `WDRDD`, `PRISTINE_DRDD`, `PRISTINE_WDRDD`, `CDD_ONE_MINIMAL`, `LITHIUM_MINIMIZE`, `DFS_ONE_MINIMAL` | `DFS` |

## Vulcan Reducer Control

| Flag | Description | Default |
| --- | --- | --- |
| `--enable-vulcan` | Enable vulcan (using auxiliary reducers to help produce smaller reduction output). | `false` |
| `--non-deletion-iteration-limit` | The maximum number of continuous non-deletion iterations allowed. | `10` |
| `--window-size` | The window size used to perform local exhaustive pattern reduction. | `4` |
| `--vulcan-fixpoint` | Enable vulcan fixpoint iteratively using auxiliary reducers until no progress can be made | `false` |

## T-Rec Reducer Control

| Flag | Description | Default |
| --- | --- | --- |
| `--enable-trec` | enable T-Rec (a lexical-syntax guided fine-grained reduction process to reduce and canonicalize each token) | `true` |

## Profiling

| Flag | Description | Default |
| --- | --- | --- |
| `--progress-dump-file` | The file to record the reduction process. The dump file can be large.. |  |
| `--actionset-effect-profile` | The file to profile the effect of edit action sets. |  |
| `--stat-dump-file` | The file to save the statistics collected during reduction. |  |
| `--profile-query-cache-time` | The file to save the profiling data of the query cache. |  |
| `--profile-query-cache-time-csv` | The file to save the profiling data of the query cache in the CSV format. |  |
| `--profile-query-cache-memory` | The file to save the profiling data of the query cache. |  |
| `--profile-actionset` | The file to save information of all the created edit action sets. |  |
| `--profile-list-minimizer` | The file to save the reduction process of the list minimizer. |  |
| `--profile-program-size-trend` | The file to save the the size of the program being reduced over time. |  |
| `--profile-for-reduction-progress-differential-analysis` | The file to save the reduction process for offline differential analysis. |  |
| `--enable-web-ui` | Serve a live web dashboard of the reduction progress on localhost. | `false` |
| `--web-ui-port` | Preferred port for --enable-web-ui. Falls back to an ephemeral port if taken. | `9000` |

## Cache Control

| Flag | Description | Default |
| --- | --- | --- |
| `--query-caching` | Enable query caching for test script executions. | `true` |
| `--default-sha-alg-type` | The SHA algorithm used in the reduction process<br>Possible values: `SHA512`, `SHA256` | `SHA256` |

## List Minimizer Microbenchmarking

| Flag | Description | Default |
| --- | --- | --- |
| `--list-minimizer-microbenchmarking-mode` | RECORD captures each list minimization problem the main reduction algorithm encounters, and refuses to run while any other stage is on (--enable-latra false --enable-trec false --dyck-node-reducer OFF --line-slicer OFF turn off the ones on by default). EVALUATE runs one minimizer against one recorded problem and reports its cost and result. Unset (the default) runs a normal reduction.<br>Possible values: `RECORD`, `EVALUATE` |  |
| `--list-minimizer-microbenchmark-output` | RECORD: the directory to write recorded microbenchmarks to, one folder each. |  |
| `--min-list-size-to-record` | RECORD: skip problems whose list is shorter than this. Lists of one or two elements leave a minimizer no room to differ, so they say nothing about which one to prefer. | `6` |
| `--max-microbenchmarks-to-record` | RECORD: stop recording after this many microbenchmarks. Unset means no bound. |  |
| `--evaluation-microbenchmark` | EVALUATE: the microbenchmark.yaml of the recorded problem to evaluate. |  |
| `--list-minimizers-to-evaluate` | EVALUATE: the list minimizers to evaluate, comma-separated or by repeating the flag. All of them are measured against the same recorded problem in one process, in the order given, each from a pristine tree and an empty query cache, and each writing to \<--evaluation-output\>/\<MINIMIZER\>/. | `[]` |
| `--evaluation-output` | EVALUATE: the root to write the metrics under, one directory per minimizer, each holding summary.jsonl and queries.jsonl. runs.jsonl at the root says what became of each. |  |

## Experiment Control

| Flag | Description | Default |
| --- | --- | --- |
| `--keep-reduction-history` | keep all the reduction folders generated during reduction | `false` |
| `--enable-error-tolerant-grammar` | when a file does not parse under its real grammar, first try an error-tolerant parse of that grammar (keeping its structure, with unparseable fragments as leaf tokens) before falling back to the Dyck/Line tolerant grammars | `true` |
| `--dyck-node-reducer` | whether to run the Dyck node reducer as an extra pass that reparses each file under a Dyck grammar and deletes balanced delimiter groups the real grammar cannot place: auto (only for files that do not parse under their real grammar), on (every file), or off<br>Possible values: `AUTO`, `ON`, `OFF` | `AUTO` |

## LPR Reducer Control

| Flag | Description | Default |
| --- | --- | --- |
| `--enable-lpr` | Enable LPR (LLM-based transformations to improve reduction results). | `false` |
| `--lpr-fixpoint` | Enable lpr fixpoint. Everytime a transformation makes progress, go to the next transformation. | `false` |
| `--llm-client-script` | The executable script used to invoke the LLM during LPR. It receives a JSON request (via --input-file) and writes a JSON array of response strings (via --output-file). If omitted, LPR falls back to a bundled default client (lpr/scripts/llm\_client.py): an OpenAI-compatible client that by default targets a local ollama server at http://localhost:11434/v1 with model codellama:13b. The fallback is reported in the reduction output when it is used. |  |

## Latra Reducer Control

| Flag | Description | Default |
| --- | --- | --- |
| `--enable-latra` | Enable Latra (language-specific transformations to produce smaller reduction output). | `true` |
| `--latra-fixpoint` | Enable fixpoint mode for running Latra reducers. | `true` |
| `--latra-transformation-list-minimizer` | The list minimizer algorithm to reduce with the found transformations<br>Possible values: `PRISTINE_DDMIN`, `PERSES_VARIANT_OF_PRISTINE`, `DFS`, `BFS`, `CDD`, `WEIGHTED_DFS`, `WEIGHTED_BFS`, `PROBDD`, `WDD`, `WPROBDD`, `WINDOWED_SLICER`, `LOCAL_EXHAUSTIVE_PATTERN_ENUMERATION`, `ONE_BY_ONE`, `ADAPTIVE_GAIN_DRIVEN`, `DRDD`, `WDRDD`, `PRISTINE_DRDD`, `PRISTINE_WDRDD`, `CDD_ONE_MINIMAL`, `LITHIUM_MINIMIZE`, `DFS_ONE_MINIMAL` | `WPROBDD` |

## SFC (Structure Form Conversion) Reducer Control

| Flag | Description | Default |
| --- | --- | --- |
| `--enable-sfc` | Enable the SFC reducers (structure form conversion, to produce smaller reduction output at the cost of more property tests). | `false` |
| `--sfc-fixpoint` | Enable fixpoint mode for running the SFC reducers. | `true` |
| `--sfc-subtree-token-count-limit` | Skip a subtree whose token count exceeds this limit: the number of structures of a subtree grows with the number of its reusable pieces. | `64` |
| `--sfc-candidate-limit` | The maximum number of candidate structures to test for a single subtree. | `64` |

## Verbosity

| Flag | Description | Default |
| --- | --- | --- |
| `--verbosity` | verbosity of logging | `INFO` |
| `--list-verbosity-levels` | list all verbosity levels |  |
| `--hide-timestamps` | hide the timestamps in the log messages | `false` |

## Version

| Flag | Description | Default |
| --- | --- | --- |
| `--version` | print the version |  |

## Help

| Flag | Description | Default |
| --- | --- | --- |
| `-h`, `--help` | print help message |  |
