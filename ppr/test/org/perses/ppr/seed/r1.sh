#!/usr/bin/env bash

# seed
rm -f out*.txt
rm a.out &> /dev/null
CFILE=seed1.c

# check undefined behavior
if
  gcc -Wall -Wextra -Wsystem-headers -O0 $CFILE >outa.txt 2>&1 &&\
  ! grep uninitialized outa.txt &&\
  ! grep 'division by zero' outa.txt &&\
  ! grep 'without a cast' outa.txt &&\
  ! grep 'control reaches end' outa.txt &&\
  ! grep 'return type defaults' outa.txt &&\
  ! grep 'cast from pointer to integer' outa.txt &&\
  ! grep 'useless type name in empty declaration' outa.txt &&\
  ! grep 'no semicolon at end' outa.txt &&\
  ! grep 'type defaults to' outa.txt &&\
  ! grep 'too few arguments for format' outa.txt &&\
  ! grep 'incompatible pointer' outa.txt &&\
  ! grep 'ordered comparison of pointer with integer' outa.txt &&\
  ! grep 'declaration does not declare anything' outa.txt &&\
  ! grep 'expects type' outa.txt &&\
  ! grep 'pointer from integer' outa.txt &&\
  ! grep 'incompatible implicit' outa.txt &&\
  ! grep 'excess elements in struct initializer' outa.txt &&\
  ! grep 'return type of \‘main\’ is not \‘int\’' outa.txt &&\
  ! grep 'comparison between pointer and integer' outa.txt
then
    : # do nothing
else
    exit 1
fi

# Check the seed program.
if ! gcc $CFILE &> out.txt ; then
  exit 1
fi
./a.out > out1.txt
if ! grep -e "world" out1.txt ; then
  exit 1
fi


# variant
rm -f out*.txt
rm a.out &> /dev/null
CFILE=variant1.c

# Check the variant program.
gcc $CFILE &> out2.txt
if ! grep -e "expected declaration or statement at end of input" out2.txt ; then
  exit 1
fi

exit 0
