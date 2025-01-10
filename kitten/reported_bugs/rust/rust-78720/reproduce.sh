#!/usr/bin/env bash
timeout -s 9 30 rustc --crate-type=staticlib -C debuginfo=2 -C opt-level=1 -C target-cpu=skylake mutant.rs