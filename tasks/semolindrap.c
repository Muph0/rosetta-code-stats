/**
 * from https://rosettacode.org/wiki/Semordnilap
 *
 * A semordnilap is a word (or phrase) that spells a different word (or phrase)
 * backward. "Semordnilap" is a word that itself is a semordnilap.
 * Example: lager and regal
 *
 * Task
 * This task does not consider semordnilap phrases, only single words.
 * Using only words from this list, report the total number of unique
 * semordnilap pairs, and print 5 examples. Two matching semordnilaps,
 * such as lager and regal, should be counted as one unique pair.
 * (Note that the word "semordnilap" is not in the above dictionary.)
 */

#include <stdio.h>
#include <stdlib.h>
#include <alloca.h> /* stdlib.h might not have obliged. */
#include <string.h>

static void reverse(char *s, int len)
{
    int i, j;
    char tmp;

    for (i = 0, j = len - 1; i < len / 2; ++i, --j)
        tmp = s[i], s[i] = s[j], s[j] = tmp;
}

/* Wrap strcmp() for qsort(). */
static int strsort(const void *s1, const void *s2)
{
    return strcmp(*(char *const *) s1, *(char *const *) s2);
}

int task_main(void)
{
    int i, c, ct = 0, len, sem = 0;
    char **words, **drows, tmp[24];
    FILE *dict = fopen("unixdict.txt", "r");

    /* Determine word count. */
    while ((c = fgetc(dict)) != EOF)
        ct += c == '\n';
    rewind(dict);

    /* Using alloca() is generally discouraged, but we're not doing
     * anything too fancy and the memory gains are significant. */
    words = alloca(ct * sizeof words);
    drows = alloca(ct * sizeof drows);

    for (i = 0; fscanf(dict, "%s%n", tmp, &len) != EOF; ++i) {
        /* Use just enough memory to store the next word. */
        strcpy(words[i] = alloca(len), tmp);

        /* Store it again, then reverse it. */
        strcpy(drows[i] = alloca(len), tmp);
        reverse(drows[i], len - 1);
    }

    fclose(dict);
    qsort(drows, ct, sizeof drows, strsort);

    /* Walk both sorted lists, checking only the words which could
     * possibly be a semordnilap pair for the current reversed word. */
    for (c = i = 0; i < ct; ++i) {
        while (strcmp(drows[i], words[c]) > 0 && c < ct - 1)
            c++;
        /* We found a semordnilap. */
        if (!strcmp(drows[i], words[c])) {
            strcpy(tmp, drows[i]);
            reverse(tmp, strlen(tmp));
            /* Unless it was a palindrome. */
            if (strcmp(drows[i], tmp) > 0 && sem++ < 5)
                printf("%s\t%s\n", drows[i], tmp);
        }
    }

    printf("Semordnilap pairs: %d\n", sem);
    return 0;
}