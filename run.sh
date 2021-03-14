#!/bin/bash

make

if test -f "./bin/engine"; then
    ./bin/engine
fi

make clean