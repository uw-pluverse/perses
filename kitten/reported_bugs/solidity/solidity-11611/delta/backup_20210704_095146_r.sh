#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 solc-trunk-asan_ubsan --optimize mutant.sol &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "Internal compiler error during compilation:" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "/solidity/libsolidity/codegen/ContractCompiler.cpp" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "Throw in function void (anonymous namespace)::StackHeightChecker::check()" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "Dynamic exception type: boost::wrapexcept<solidity::langutil::InternalCompilerError>" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "std::exception::what: I sense a disturbance in the stack: 4 vs 3" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "[solidity::util::tag_comment*] = I sense a disturbance in the stack: 4 vs 3" "${OUTPUT}" ; then
  exit 1
fi
exit 0