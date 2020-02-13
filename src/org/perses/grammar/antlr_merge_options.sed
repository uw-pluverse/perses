#!/bin/sed -rf

:cycle 
# Load line...
N

# Match options...
/\<options\s+\{/ {
  # Clear the options fragment
  s/\<options\s+\{//
  # Swap pattern buffer and hold buffer,
  # so pattern buffer contains options, hold buffer contains
  # other lines.
  x
:repeat
  # Match a }, finish up.
  /}/ {
    # Remove trailing }
    s/}//
    # Swap pattern buffer and hold buffer
    x
    # Restart
    b cycle;
  }
  # Load line into pattern
  N;
  b repeat;
};

# Repeat
$!b cycle

# Last line, print hold buffer, swap, print rest of grammar
x
/./{
  s/(.*)/options {\1}/;
  p;
}
x
# (pattern is implicitly printed)
