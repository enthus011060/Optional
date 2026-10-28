// conversioni.c

#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

#include "conversioni.h"

Option_int to_int(const char *s)
{
    if (s == NULL || *s == '\0')
    {
        fprintf(stderr, "Errore: stringa vuota o NULL\n");
        return NONE(int);
    }

    char *endptr;
    errno = 0;

    long val = strtol(s, &endptr, 10);

    if (s == endptr ||
        errno == ERANGE ||
        *endptr != '\0' ||
        val < INT_MIN ||
        val > INT_MAX)
    {
        fprintf(stderr, "Errore: conversione non valida\n");
        return NONE(int);
    }

    return SOME(int, (int)val);
}
