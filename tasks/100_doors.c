/**
 * from https://rosettacode.org/wiki/100_doors
 *
 * There are 100 doors in a row that are all initially closed.
 * You make 100 passes by the doors.
 * The first time through, visit every door and  toggle  the door  (if the door is closed,  open it;   if it is open,  close it).
 * The second time, only visit every 2nd door   (door #2, #4, #6, ...),   and toggle it.
 * The third time, visit every 3rd door   (door #3, #6, #9, ...), etc,   until you only visit the 100th door.
 *
 * Task
 * Answer the question:   what state are the doors in after the last pass?   Which are open, which are closed?
 */

#include <stdio.h>
#include <stdlib.h>

#define DOORS 400000 // increased the number of doors to run longer

int task_main()
{
    char *is_open = malloc(DOORS);
    for (int i = 0; i < DOORS; i++)
        is_open[i] = 0;

    int pass, door;

    /* do the passes */
    for (pass = 0; pass < DOORS; ++pass)
        for (door = pass; door < DOORS; door += pass + 1)
            is_open[door] = !is_open[door];

    /* output the result */
    // for (door = 0; door < DOORS; ++door)
    //     printf("door #%d is %s.\n", door + 1, (is_open[door] ? "open" : "closed"));

    free(is_open);

    return 0;
}