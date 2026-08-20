#!/usr/bin/env bash

set -o nounset

# Two files written in *different languages* (C and Java) reduced together against a single
# interestingness test: each file must keep its own marker, so neither can be emptied and each is
# parsed/reduced by the facade for its own language. The marker is a plain token match (no compiler),
# so the test is hermetic and deterministic.
grep -q "keep_c" prog.c && grep -q "keep_java" App.java
