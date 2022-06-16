#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>

int task_main(void);

static long delta_usec(struct timeval* start, struct timeval* stop)
{
    return (stop->tv_sec - start->tv_sec) * 1000L * 1000L //
           + (stop->tv_usec - start->tv_usec);
}

#define SAMPLES 25
#define OUTFILE "/dev/null" //OUTDIR "/" TASK_NAME ".out"

int main()
{
    struct timeval start, stop;

    fprintf(stderr, "Measuring task \033[1m%s\033[0m >%s\n", TASK_NAME, OUTFILE);
    for (int i = 0; i < SAMPLES; i++)
    {
        gettimeofday(&start, NULL);
        task_main();
        gettimeofday(&stop, NULL);
        long usec = delta_usec(&start, &stop);
        printf("%.6f\n", usec / 1000.0);
    }
}