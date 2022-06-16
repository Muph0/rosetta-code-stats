#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int task_main(void);

static long delta_usec(struct timeval* start, struct timeval* stop)
{
    return (stop->tv_sec - start->tv_sec) * 1000L * 1000L //
           + (stop->tv_usec - start->tv_usec);
}

#define SAMPLES 25

int main()
{
    struct timeval start, stop;
    FILE* fnull = fopen("/dev/null", "w");
    FILE* stdout_saved = stdout;

    fprintf(stderr, "Measuring task \033[1m%s\033[0m... (data in ms)\n", TASK_NAME);
    for (int i = 0; i < SAMPLES; i++)
    {
        stdout = fnull;
        gettimeofday(&start, NULL);
        task_main();
        gettimeofday(&stop, NULL);
        stdout = stdout_saved;

        long usec = delta_usec(&start, &stop);
        printf("%.3f\n", usec / 1000.0);
    }
}