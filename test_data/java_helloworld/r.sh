#!/usr/bin/env bash

set -o pipefail
set -o nounset

rm t.class
javac t.java \
&& timeout -s 9 5 java t | grep -q 'hello world'
