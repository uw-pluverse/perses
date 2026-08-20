#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

if [[ "$#" != 2 ]] ; then
  echo "$0 <source-jar> <target-jar>"
  exit 1
fi

readonly SOURCE_JAR="${1}"

readonly TARGET_JAR="${2}"

# Staging must be atomic. Writing the ~80MB jar straight to TARGET_JAR truncates it and then
# streams the content in, so anyone reading it meanwhile -- e.g. a concurrent benchmark sweep,
# where every worker restages these jars and reads them from a container -- sees a torn jar and
# dies with a ClassNotFoundException on a class that is merely not written yet. Build beside the
# target and rename: rename(2) within a filesystem is atomic, so a reader sees either the whole
# old jar or the whole new one, and a reader holding the old fd keeps a valid jar.
#
# mktemp gives each concurrent writer its own scratch file, so they cannot corrupt each other's.
temp_jar=$(mktemp "${TARGET_JAR}.XXXXXX")
trap 'rm -f "${temp_jar}"' EXIT

# shellcheck disable=SC2016
echo -e '#!/usr/bin/env bash \nexec java -jar "$0" "$@"' | cat - "${SOURCE_JAR}" > "${temp_jar}"
chmod +x "${temp_jar}"
mv -f "${temp_jar}" "${TARGET_JAR}"