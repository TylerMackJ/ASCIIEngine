#!/bin/bash

make gdb

if test -f "./bin/engine"; then
    gdb ./bin/engine
fi

make clean