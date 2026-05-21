#include <stdio.h>
#include <stdlib.h>

#include "dyarr.h"

int main(void)
{
    Dyarr a;
    int p = -1;
    dyarr_init(&a, sizeof(int ));
    for(int i = 0; i < 20; i++)
    {
        // *((int *)a.arr + i) = i;
        // ((int *)a.arr)[i] = i;
        dyarr_append(&a, &i);
    }
    dyarr_append(&a, &p);
    dyarr_set(&a, 10, &p);
    for(int i = 0; i < a.len; i++)
    {
        // printf("%d ", *((int *)a.arr + i));
        // int *c = (int *)dyarr_get(&a, i);
        printf("%d ", *((int *)dyarr_get(&a, i)));
    }
    putchar('\n');
    printf("following content is elements about Dyarr a:\n");
    printf("\tarr:       %p\n"
           "\tlen:       %zu\n"
           "\telem_size: %zu\n"
           "\tcpacity:   %zu\n", a.arr, a.len, a.elem_size, a.capacity);
    dyarr_free(&a);
    return 0;
}

