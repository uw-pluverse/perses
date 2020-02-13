#!/bin/sed -rf

# Match options...
/\<options\s+\{/ {
:repeat
  s/\<tokenVocab\>=\<\w+\>\;//g

  # Match a }, finish up.
  /}/b done;

  # Load next line, repeat
  $!N;
  b repeat;
};

:done
