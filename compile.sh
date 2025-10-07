#!/bin/bash

PROGRAM_NAME="cmpval"
C_STANDARD="c99"

echo "
Compiling into $PROGRAM_NAME ..."

gcc -std="$C_STANDARD" -pedantic -Wall -Wextra -Werror  main.c compare.c -o $PROGRAM_NAME
