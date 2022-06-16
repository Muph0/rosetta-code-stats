#!/bin/bash

source build.conf

mkdir -p "$OUTDIR"
echo "time;task;opt" > "$OUTDIR/data.csv"

for lvl in $(seq 0 3); do
    flag="-O$lvl"
    echo -e "Building with \e[31m$flag\e[0m"
    ./build-tasks.sh $flag && ./run-measure.sh

    for task_src in $(ls tasks | grep .*\.c\$); do
        task=$(basename "$task_src" .c)

        while read -r line; do
            echo $(echo $line | tr '.' ',')";$task;O$lvl" >> "$OUTDIR/data.csv"
        done < "$OUTDIR/$task.csv"
    done
done




