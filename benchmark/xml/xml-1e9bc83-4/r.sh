#!/usr/bin/env bash

# Longest per-process wall cap in this script is 30s (enforced by `timeout`);
# set the CPU limit to 2x=60s so real runs finish, but a process that outlives
# `timeout` (e.g. a compiler grandchild orphaned when its driver was SIGKILLed) is
# reaped by the kernel via RLIMIT_CPU, which `timeout` cannot reach across reparenting.
# The value below is in CPU seconds (ulimit -t sets RLIMIT_CPU).
ulimit -t 60

TIMEOUT=30

GOOD_VERSION="1e9bc83"
BAD_VERSION="816b386"

if [ -z "${XML_JAR_DIR}" ]; then
  echo "Error: XML_JAR_DIR is not set."
  exit 1
fi

QUERY='declare namespace cPf ="Yz";declare namespace epDig ="ORjLoTVNxGpCRkDWrvr";declare namespace GM ="dxBB";declare namespace WWk ="PTRAuxfEpxgZi";declare namespace l ="Yz";declare namespace kXXyq ="ORjLoTVNxGpCRkDWrvr";//Y16[(boolean(reverse(.)) and (not(boolean(substring(reverse(local-name()), 16, 3) ! string-length(translate(., "!L4e9", "WB")))) or contains(namespace-uri-from-QName(node-name()), "85.`a  qnYM^3SiL(| iE") = true())) and not((@e10) > 80100.484)]/*[boolean(boolean(position()))]/following::U31[(. = <A>2</A> or boolean(last())) and (boolean(./ancestor::E8/*) or boolean(count(.)))]/descendant-or-self::*/(/E8/S6/B1/S13/U31)[(boolean(boolean(boolean(last())) castable as xs:string) and not(boolean(count(subsequence(head(head(node-name())), 40, 7) ! .)))) and not(tail(subsequence(./preceding-sibling::*/(/E8/S6/B1/S13/O19), 7, 2)) = ())]/self::U31[not(boolean(count(subsequence(tail(subsequence(. = <A>2</A>, 48)), 44))))]/self::*[boolean(math:cos(count(.)) div 2.1) and boolean(./ancestor-or-self::*/(A11/H11,J8/L4))]/ancestor-or-self::*[(count(. ! .) = 934794799) != true() or (boolean(head(subsequence(./descendant-or-self::F9, 39))) and boolean(J5/P17/C19))]/(C7,U8,/E8/S6/B1/S13/U31)'
echo $QUERY > query.xq

# run reference
reference="saxon"
timeout -s 9 $TIMEOUT java -cp "${XML_JAR_DIR}/saxon-he-12.4.jar:${XML_JAR_DIR}/xmlresolver-5.2.0.jar" \
  net.sf.saxon.Query -s:./input.xml -q:./query.xq > ${reference}_raw_result.xml 2>&1
ret=$?

if [ $ret != 0 ]; then
  exit 1
fi

# run basex_bad
target_basex_bad="basex_bad"
timeout -s 9 $TIMEOUT java -cp "${XML_JAR_DIR}/basex-${BAD_VERSION}.jar" \
  org.basex.BaseX -i input.xml query.xq > ${target_basex_bad}_raw_result.xml 2>&1
ret=$?

if [ $ret != 0 ]; then
  exit 1
fi

# run basex_good
target_basex_good="basex_good"
timeout -s 9 $TIMEOUT java -cp "${XML_JAR_DIR}/basex-${GOOD_VERSION}.jar" \
  org.basex.BaseX -i input.xml query.xq > ${target_basex_good}_raw_result.xml 2>&1
ret=$?

if [ $ret != 0 ]; then
  exit 1
fi

# process saxon result
grep -o 'id="[^"]*"' ${reference}_raw_result.xml \
  | grep -v '^[[:space:]]*$' > ${reference}_processed_result.txt

# process basex_bad result
grep -o 'id="[^"]*"' ${target_basex_bad}_raw_result.xml \
  | grep -v '^[[:space:]]*$' > ${target_basex_bad}_processed_result.txt

# process basex_good result
grep -o 'id="[^"]*"' ${target_basex_good}_raw_result.xml \
  | grep -v '^[[:space:]]*$' > ${target_basex_good}_processed_result.txt

# the output of bad basex version should be different from the output of reference
if diff ${reference}_processed_result.txt ${target_basex_bad}_processed_result.txt > /dev/null 2>&1; then
  exit 1
fi

# the output of good basex version should be the same as the output of reference
if ! diff ${reference}_processed_result.txt ${target_basex_good}_processed_result.txt > /dev/null 2>&1; then
  exit 1
fi

exit 0
