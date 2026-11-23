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
