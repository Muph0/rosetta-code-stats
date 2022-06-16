#!/bin/bash

source build.conf

CFLAGS="$@"
mkdir -p "$OUTDIR"

ln -fs ../tasks/unixdict.txt out/unixdict.txt

for task_src in $(ls tasks | grep .*\.c\$); do
    task=$(basename "$task_src" .c)

    COMMAND=$(echo gcc "measure.c" "tasks/$task_src" -o "$OUTDIR/$task" "-DTASK_NAME=\"$task\"" "-DOUTDIR=\"$OUTDIR\"" $CFLAGS)

    echo $COMMAND
    $COMMAND
done

