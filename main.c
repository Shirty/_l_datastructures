#include <stdlib.h>
#include <stdio.h>
#include "vector_array.h"

int main(int argc, char* argv[])
{
    varray_t_ptr arr = create_varray();
    varray_add(arr, 12);
    varray_add(arr, 293);
    varray_add(arr, 1);
    varray_add(arr, 21);
    varray_add(arr, 5);
    varray_add(arr, 00);
    varray_add(arr, 12);
    varray_add(arr, 29);
    varray_add(arr, 1000);
    varray_add(arr, 100000);
    varray_add(arr, 11);
    varray_add(arr, 1);
    varray_add(arr, 10000000);
    varray_add(arr, 2);
    varray_add(arr, 293);
    varray_add(arr, 2874);
    varray_add(arr, 1297);
    varray_add(arr, 286);
    varray_add(arr, 9288);
    varray_add(arr, 2889);
    varray_add(arr, 892810);
    varray_del(arr, 1);

    varray_destroy(arr);
    // varray_print(arr);
    return EXIT_SUCCESS;
}
