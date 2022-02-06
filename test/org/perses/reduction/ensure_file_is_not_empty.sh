#!/usr/bin/env bash

if [[ "$#" != 1 ]] ; then
  echo "Usage: $0 <file>"
  exit 1
fi

if [[ $(wc -l < "${1}") -ge 1 ]] ; then
  exit 0
else
  cat "${1}" 1>&2
  exit 1
fi