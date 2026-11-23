#!/usr/bin/env bash
#
# Sources the script `perses --help-completion` prints and checks the candidates it
# offers for representative command lines.

set -o nounset
set -o pipefail

readonly SCRIPT="$1"
source "${SCRIPT}"

readonly WORK="$(mktemp -d)"
trap 'rm -rf "${WORK}"' EXIT
touch "${WORK}/r.sh" "${WORK}/t.c"
cd "${WORK}"

failures=0

# complete_for <expected candidates, space separated> <command words>...
# The last command word is the one being completed; pass "" for an empty word.
complete_for() {
  local expected="$1"
  shift
  COMP_WORDS=("$@")
  COMP_CWORD=$((${#COMP_WORDS[@]} - 1))
  COMPREPLY=()
  _perses__complete
  local actual
  actual="$(printf '%s\n' "${COMPREPLY[@]}" | sort | tr '\n' ' ')"
  actual="${actual% }"
  local sorted_expected
  sorted_expected="$(tr ' ' '\n' <<< "${expected}" | sort | tr '\n' ' ')"
  sorted_expected="${sorted_expected% }"
  if [[ "${actual}" == "${sorted_expected}" ]]; then
    echo "PASS: [$*] -> ${actual}"
  else
    echo "FAIL: [$*]"
    echo "  expected: ${sorted_expected}"
    echo "  actual:   ${actual}"
    failures=$((failures + 1))
  fi
}

complete_for "--test-script --test" perses --tes
complete_for "--input-file --input" perses --test-script r.sh --inp
complete_for "true false" perses --fixpoint ""
complete_for "false" perses --fixpoint f
complete_for "COMPACT_ORIG_FORMAT COMPACT_PYTHON3_FORMAT" perses --code-format COMP
complete_for "r.sh t.c" perses --test-script ""
complete_for "r.sh" perses -t r
complete_for "" perses --threads ""

if [[ "$(complete -p perses)" != "complete -F _perses__complete perses" ]]; then
  echo "FAIL: the script did not register _perses__complete for perses"
  failures=$((failures + 1))
fi

# A switch takes no value, so the word after it is completed as a flag again.
COMP_WORDS=(perses --help "")
COMP_CWORD=2
COMPREPLY=()
_perses__complete
if [[ " ${COMPREPLY[*]} " != *" --test-script "* ]]; then
  echo "FAIL: flags are not offered after a switch"
  failures=$((failures + 1))
fi
if [[ " ${COMPREPLY[*]} " == *" --help-completion "* ]]; then
  echo "FAIL: the hidden --help-completion flag is offered"
  failures=$((failures + 1))
fi

if [[ "${failures}" -ne 0 ]]; then
  echo "${failures} check(s) failed"
  exit 1
fi
echo "All checks passed"
