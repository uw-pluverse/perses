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

if ! grep --quiet --fixed-strings "/solidity/libsolidity/ast/Types.cpp" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "Throw in function virtual unsigned int solidity::frontend::ArrayType::calldataEncodedSize(bool) const" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "Dynamic exception type: boost::wrapexcept<solidity::langutil::InternalCompilerError>" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "std::exception::what: Array size does not fit unsigned." "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "[solidity::util::tag_comment*] = Array size does not fit unsigned." "${OUTPUT}" ; then
  exit 1
fi
exit 0