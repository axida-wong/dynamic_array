#ifndef DYARR_H
#define DYARR_H

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_DYARR_SIZE 10


typedef struct dyarr
{
    void *arr;
    size_t len;
    size_t elem_size;
    size_t capacity;
} Dyarr;

void dyarr_init(Dyarr *da, size_t elem_size);

void *dyarr_get(Dyarr *da, size_t i);

void dyarr_set(Dyarr *da, size_t i, void *value);

void dyarr_append(Dyarr *da, void *value);

void dyarr_free(Dyarr *da);

#endif