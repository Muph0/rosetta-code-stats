#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <err.h>
#include <errno.h>
#include <limits.h>

int task_main(void);

static long delta_usec(struct timeval *start, struct timeval *stop)
{
    return (stop->tv_sec - start->tv_sec) * 1000L * 1000L //
           + (stop->tv_usec - start->tv_usec);
}

static long parse_number(char *text)
{
    char *end;
    errno = 0;
    long l = strtol(text, &end, 10); // 0 if you want octal/hex/decimal

    if (end == text || *end != '\0' || ((l == LONG_MIN || l == LONG_MAX) && errno == ERANGE))
        err(1, "bad integer format: %s", text);
    return l;
}

#define OUTFILE "/dev/null" // OUTDIR "/" TASK_NAME ".out"

int main(int argc, char *argv[])
{
    struct timeval start, stop;
    int samples = 25;

    switch (argc)
    {
    case 1:
        break;
    case 2:
        samples = parse_number(argv[1]);
        break;

    default:
        err(1, "too many arguments");
    }

    fprintf(stderr, "Measuring task \033[1m%s\033[0m >%s\n", TASK_NAME, OUTFILE);
    for (int i = 0; i < samples; i++)
    {
        gettimeofday(&start, NULL);
        task_main();
        gettimeofday(&stop, NULL);
        long usec = delta_usec(&start, &stop);
        printf("%.6f\n", usec / 1000.0);
    }
}