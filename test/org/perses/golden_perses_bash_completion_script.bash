# Bash completion for the perses command.
#
# `perses --help-completion` prints this template followed by the definition
# of PERSES_COMPLETION_FLAGS: one line per flag name, each followed by a
# suffix that says how the flag's value is completed (the same scheme as
# `bazel help completion`):
#
#   --help                 a switch that takes no value
#   --fixpoint={true,false}
#   --code-format={A,B,C}  one of the listed constants
#   --test-script=path     a file or directory
#   --threads=             a free-form value; nothing is offered
#
# perses takes every value as the next word (`--test-script r.sh`), never as
# `--flag=value`, so the `=` in the metadata is only a separator for this
# script and is never inserted on the command line.
#
# Zsh loads this script too after `autoload -U +X bashcompinit && bashcompinit`,
# which is why it uses no bash builtin that bashcompinit does not emulate
# faithfully: no mapfile, no compgen, and compopt only where it exists.

_perses__flag_names() {
  local line
  while IFS= read -r line; do
    [[ -z "$line" ]] && continue
    printf '%s\n' "${line%%=*}"
  done <<< "$PERSES_COMPLETION_FLAGS"
}

# Prints the metadata line for the flag named $1, if any.
_perses__flag_line() {
  local line
  while IFS= read -r line; do
    if [[ "${line%%=*}" == "$1" ]]; then
      printf '%s\n' "$line"
      return 0
    fi
  done <<< "$PERSES_COMPLETION_FLAGS"
  return 1
}

# Appends to COMPREPLY the words among $2.. that start with $1.
_perses__add_matching() {
  local prefix="$1" word
  shift
  for word in "$@"; do
    [[ "$word" == "$prefix"* ]] && COMPREPLY+=("$word")
  done
}

# Appends to COMPREPLY the files and directories that start with $1.
_perses__add_paths() {
  if command -v _filedir > /dev/null 2>&1; then
    _filedir
    return
  fi
  if command -v compopt > /dev/null 2>&1; then
    compopt -o filenames 2> /dev/null
  fi
  local path
  for path in "$1"*; do
    [[ -e "$path" ]] && COMPREPLY+=("$path")
  done
}

_perses__complete() {
  local cur prev
  COMPREPLY=()
  cur="${COMP_WORDS[COMP_CWORD]}"
  prev=""
  if ((COMP_CWORD > 0)); then
    prev="${COMP_WORDS[COMP_CWORD - 1]}"
  fi

  local prev_line=""
  if [[ "$prev" == -* ]]; then
    prev_line="$(_perses__flag_line "$prev")" || prev_line=""
  fi

  # The previous word is a flag that takes a value: complete that value.
  if [[ "$prev_line" == *=* && "$cur" != -* ]]; then
    local spec="${prev_line#*=}"
    case "$spec" in
      path)
        _perses__add_paths "$cur"
        ;;
      \{*\})
        spec="${spec#\{}"
        spec="${spec%\}}"
        # shellcheck disable=SC2086
        _perses__add_matching "$cur" ${spec//,/ }
        ;;
      *) ;;
    esac
    return 0
  fi

  # shellcheck disable=SC2046
  _perses__add_matching "$cur" $(_perses__flag_names)
}

complete -F _perses__complete perses

# The flag list below is generated from the flag definitions.
PERSES_COMPLETION_FLAGS="
--actionset-effect-profile=path
--alg=
--call-creduce={true,false}
--call-formatter={true,false}
--cleanup-alg=
--code-format={SINGLE_TOKEN_PER_LINE,ORIG_FORMAT,COMPACT_ORIG_FORMAT,PYTHON3_FORMAT,COMPACT_PYTHON3_FORMAT,YAML_FORMAT}
--creduce-cmd=
--default-list-minimizer-for-kleene={PRISTINE_DDMIN,PERSES_VARIANT_OF_PRISTINE,DFS,BFS,CDD,WEIGHTED_DFS,WEIGHTED_BFS,PROBDD,WDD,WPROBDD,WINDOWED_SLICER,LOCAL_EXHAUSTIVE_PATTERN_ENUMERATION,ONE_BY_ONE,ADAPTIVE_GAIN_DRIVEN,DRDD,WDRDD,PRISTINE_DRDD,PRISTINE_WDRDD,CDD_ONE_MINIMAL,LITHIUM_MINIMIZE,DFS_ONE_MINIMAL}
--default-sha-alg-type={SHA512,SHA256}
--deps=path
--dyck-node-reducer={AUTO,ON,OFF}
--enable-error-tolerant-grammar={true,false}
--enable-latra={true,false}
--enable-lpr={true,false}
--enable-sfc={true,false}
--enable-token-slicer={true,false}
--enable-trec={true,false}
--enable-tree-slicer={true,false}
--enable-vulcan={true,false}
--enable-web-ui={true,false}
--evaluation-microbenchmark=path
--evaluation-output=path
--fixpoint={true,false}
--format-cmd=
--global-fixpoint={true,false}
--help
--hide-timestamps={true,false}
--input-file=path
--input=path
--keep-reduction-history={true,false}
--lang=
--language-ext-jars=path
--latra-fixpoint={true,false}
--latra-transformation-list-minimizer={PRISTINE_DDMIN,PERSES_VARIANT_OF_PRISTINE,DFS,BFS,CDD,WEIGHTED_DFS,WEIGHTED_BFS,PROBDD,WDD,WPROBDD,WINDOWED_SLICER,LOCAL_EXHAUSTIVE_PATTERN_ENUMERATION,ONE_BY_ONE,ADAPTIVE_GAIN_DRIVEN,DRDD,WDRDD,PRISTINE_DRDD,PRISTINE_WDRDD,CDD_ONE_MINIMAL,LITHIUM_MINIMIZE,DFS_ONE_MINIMAL}
--line-slicer={AUTO,ON,OFF}
--list-algs
--list-langs
--list-list-minimizers
--list-minimizer-microbenchmark-output=path
--list-minimizer-microbenchmarking-mode={RECORD,EVALUATE}
--list-minimizers-to-evaluate={PRISTINE_DDMIN,PERSES_VARIANT_OF_PRISTINE,DFS,BFS,CDD,WEIGHTED_DFS,WEIGHTED_BFS,PROBDD,WDD,WPROBDD,WINDOWED_SLICER,LOCAL_EXHAUSTIVE_PATTERN_ENUMERATION,ONE_BY_ONE,ADAPTIVE_GAIN_DRIVEN,DRDD,WDRDD,PRISTINE_DRDD,PRISTINE_WDRDD,CDD_ONE_MINIMAL,LITHIUM_MINIMIZE,DFS_ONE_MINIMAL}
--list-parser-facades
--list-verbosity-levels
--llm-client-script=path
--lpr-fixpoint={true,false}
--max-microbenchmarks-to-record=
--max-slicing-window-size=
--min-list-size-to-record=
--min-slicing-window-size=
--non-deletion-iteration-limit=
--output-dir=path
--parser-facade-class-name=
--profile-actionset=path
--profile-for-reduction-progress-differential-analysis=path
--profile-list-minimizer=path
--profile-program-size-trend=path
--profile-query-cache-memory=path
--profile-query-cache-time-csv=path
--profile-query-cache-time=path
--progress-dump-file=path
--query-caching={true,false}
--reparse-each-iteration={true,false}
--script-execution-keep-waiting-after-timeout={true,false}
--script-execution-timeout-in-seconds=
--sfc-candidate-limit=
--sfc-fixpoint={true,false}
--sfc-subtree-token-count-limit=
--stat-dump-file=path
--test-script=path
--test=path
--threads=
--verbosity=
--version
--vulcan-fixpoint={true,false}
--web-ui-port=
--window-size=
-h
-i=path
-o=path
-t=path
"
