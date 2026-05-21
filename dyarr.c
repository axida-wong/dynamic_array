#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dyarr.h"

void dyarr_init(Dyarr *da, size_t elem_size)
{
    if (da == NULL)
        return ; // safty check
    void *memory = (void *)malloc(DEFAULT_DYARR_SIZE * elem_size);
    if (memory == NULL)
    {
        perror("Faild to allocate initial memory for Dyarr");
        return ;
    }

    *da = (Dyarr ) {
        .len = 0,
        .elem_size = elem_size,
        .capacity = DEFAULT_DYARR_SIZE * elem_size,
        .arr = memory
    };
}

void *dyarr_get(Dyarr *da, size_t i)
{
    if (da == NULL) 
        return NULL;

    if (i < 0 || i >= da->len)
    {
        fprintf(stderr, "%d is out of available index\n", i);
        return NULL;
    }
    char *current = (char *)da->arr + i * da->elem_size;

    return (void *)current;
}

void dyarr_set(Dyarr *da, size_t i, void * value)
{
    if (da == NULL)
        return ;
    if (i < 0)
    {
        fprintf(stderr, "index can't be minus.\n");
        return ;
    }

    if (i >= da->len)
    {
        fprintf(stderr, "index is out of available lenth.\n");
        return ;
    }
    
    memcpy((char *)da->arr + i * da->elem_size, value, da->elem_size);
}

void dyarr_append(Dyarr *da, void *value)
{
    if (da == NULL)
        return ;

    if (da->len *da->elem_size < da->capacity)
    {
        memcpy((char *)da->arr + da->len * da->elem_size, value, da->elem_size);
        da->len++;
    }
    else
    {
        void *tmp = realloc(da->arr, da->capacity * 2);
        if(!tmp)
        {
            fprintf(stderr, "realloc failed\n");
            return ;
        }
        da->capacity *= 2;
        // dyarr_append(da, value);
        memcpy((char *)da->arr + da->len * da->elem_size, value, da->elem_size);
        da->len++;
    }
}

void dyarr_free(Dyarr *da)
{
    free(da->arr);

    da->arr = NULL;
    da->capacity = 0;
    da->len = 0;
    da->elem_size = 0;
}