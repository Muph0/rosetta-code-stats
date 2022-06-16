#!/bin/bash

source build.conf

mkdir -p "$OUTDIR"

ln -fs ../tasks/unixdict.txt out/unixdict.txt

for task_src in $(ls tasks | grep .*\.c\$); do
    task=$(basename "$task_src" .c)

    cc "measure.c" "tasks/$task_src" -o "$OUTDIR/$task" \
        "-DTASK_NAME=\"$task\"" "-DOUTDIR=\"$OUTDIR\"" $CFLAGS
done

