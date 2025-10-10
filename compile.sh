#!/bin/bash

PROGRAM_NAME="cmpval"
C_STANDARD="c99"

echo "
Compiling into $PROGRAM_NAME ..."

gcc -std="$C_STANDARD" -pedantic -Wall -Wextra -Werror  src/main.c src/gsconfig.c src/compare.c src/sort-t.c src/treatargs.c 'src/test.c' -o $PROGRAM_NAME

echo "
Process complete.
"
