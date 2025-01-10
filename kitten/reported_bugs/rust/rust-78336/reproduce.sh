#!/usr/bin/env bash
timeout -s 9 30 rustc --crate-type=staticlib -C debuginfo=2 -C opt-level=z -C target-cpu=skylake mutant.rs