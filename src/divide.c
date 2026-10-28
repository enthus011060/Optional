// divide.c

#include <stdio.h>
#include "divide.h"

static const char *const MESSAGE = "Error: division by zero\n";

Option_int divide_int(int numeratore, int denominatore)
{
    if (denominatore == 0)
    {
        fprintf(stderr, "%s", MESSAGE);
        return NONE(int);
    }

    return SOME(int, numeratore / denominatore);
}

Option_double divide_double(double numeratore, double denominatore)
{
    if (denominatore == 0.0)
    {
        fprintf(stderr, "%s", MESSAGE);
        return NONE(double);
    }

    return SOME(double, numeratore / denominatore);
}