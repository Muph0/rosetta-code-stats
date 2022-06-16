#!/bin/bash

source build.conf
cd "$OUTDIR"

for lvl in $(seq 0 3); do
    flag="-O$lvl"
    echo -e "Building with \e[31m$flag\e[0m"
    ./build-tasks.sh -O0 && ./run-measure.sh

    cp "measured.csv" "data.O$lvl.csv"
done




