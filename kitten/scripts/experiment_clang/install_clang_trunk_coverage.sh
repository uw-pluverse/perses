#!/usr/bin/env bash
echoerr() { echo "ERROR: $@" 1>&2; }

set -o errexit
set -o pipefail
set -o nounset

if [[ "$#" != "1" ]] ; then
  echo "$0 <install dir>"
  exit 1
fi

# user-defined: where to build, and where to install
readonly BUILDROOT="$(readlink -f $1)"

readonly SRC_FOLDER_NAME="llvm-project"
readonly BUILD_FOLDER_NAME="llvm-build-trunk"
readonly BU_SRC_FOLDER_NAME="binutils-src"
readonly BU_BUILD_FOLDER_NAME="binutils-build"
readonly INSTALLROOT="$(readlink -f $1)"

readonly NCPUS=8

cd "${BUILDROOT}"
rm -rf * || true # remove everything in the build root folder
git clone --depth 1 https://github.com/llvm/llvm-project.git

##################################################
# Build Gold Linker
##################################################
readonly BINUTIL_TAR_FOLDER_NAME="binutils-2.26"
readonly BINUTIL_TAR_NAME="${BINUTIL_TAR_FOLDER_NAME}.tar.gz"
rm -rf "${BU_SRC_FOLDER_NAME}" "${BINUTIL_TAR_FOLDER_NAME}" "${BINUTIL_TAR_NAME}" || true
wget ftp://sourceware.org/pub/binutils/releases/${BINUTIL_TAR_NAME}
tar xf ${BINUTIL_TAR_NAME}
mv ${BINUTIL_TAR_FOLDER_NAME} ${BU_SRC_FOLDER_NAME}
#if [ ! -d "${BU_SRC_FOLDER_NAME}" ] ; then
#  git clone --depth 1 git://sourceware.org/git/binutils-gdb.git "${BU_SRC_FOLDER_NAME}" > /dev/null
#else
#  (cd ${BU_SRC_FOLDER_NAME} ; git pull) > /dev/null
#fi

rm -rf "${BU_BUILD_FOLDER_NAME}"
mkdir -p "${BU_BUILD_FOLDER_NAME}"
cd "${BU_BUILD_FOLDER_NAME}"
../${BU_SRC_FOLDER_NAME}/configure --enable-gold --enable-plugins --disable-werror > /dev/null
make all-gold -j${NCPUS} > /dev/null

cd "${BUILDROOT}"

##################################################
# Build LLVM
##################################################
rm -rf "${BUILD_FOLDER_NAME}"
mkdir -p "${BUILD_FOLDER_NAME}"
cd ${BUILD_FOLDER_NAME}

cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=${INSTALLROOT} \
  -DCMAKE_C_FLAGS="--coverage" \
  -DCMAKE_CXX_FLAGS="--coverage" \
  -DCMAKE_BUILD_TYPE=Release \
  -DLLVM_ENABLE_ASSERTIONS=ON \
  -DLLVM_ENABLE_PROJECTS="clang;;clang-tools-extra;compiler-rt;polly" \
  -DLLVM_BINUTILS_INCDIR=${BUILDROOT}/${BU_SRC_FOLDER_NAME}/include \
  ../${SRC_FOLDER_NAME}/llvm
#  -DLLVM_BUILD_32_BITS=ON \

#../${SRC_FOLDER_NAME}/configure --enable-optimized --enable-assertions \
#        --prefix=${INSTALLROOT} \
#        --with-binutils-include=${BUILDROOT}/${BU_SRC_FOLDER_NAME}/include \
#        --disable-bindings > /dev/null
# make update > /dev/null

#cmake --build . > /dev/null
#cmake --build . --target install > /dev/null

make -j ${NCPUS} > /dev/null
make install > /dev/null
