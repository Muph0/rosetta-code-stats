#!/bin/bash

source build.conf
cd "$OUTDIR"

names=""

for task_src in $(ls ../tasks | grep .*\.c\$); do
    task=$(basename "$task_src" .c)
    names="$names $task.csv"

    echo "$task" > "$task.csv"
    "./$task" 1>>  "$task.csv"
done

paste $names | tr '\t' ',' > measured.csv
