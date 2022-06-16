#!/bin/bash

source build.conf

for lvl in $(seq 0 3); do
    flag="-O$lvl"
    echo -e "Building with \e[31m$flag\e[0m"
    ./build-tasks.sh $flag && ./run-measure.sh

    cp "$OUTDIR/measured.csv" "$OUTDIR/data.O$lvl.csv"
done




