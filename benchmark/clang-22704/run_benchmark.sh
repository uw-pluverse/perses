#!/usr/bin/env bash

set -o pipefail
set -o errexit
set -o nounset

for i in {1..10} ; do
  echo $i
  ../perses_wrapper.sh --test-script r.sh --input-file small.c --fixpoint true \
      --threads 1 \
      --edit-caching true \
      --profile-query-cache "query_cache_profile_threshold_${i}.txt" \
      --query-cache-refresh-threshold "${i}/100" \
      --query-caching true \
      --stat-dump-file "stat_${i}.txt"
done