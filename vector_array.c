#include <stdlib.h>
#include <stdio.h> /* #todo_seb mainly to for testing*/
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "vector_array.h"

/* #todo_seb does not resize downwards!!*/
/* #todo_seb should probably int size*/
// const int DEFAULT_SIZE = 
#define DEFAULT_SIZE 10 // 40 bytes which is 10 integers
#define AUGMENT_MULTIPLE 2
/* #todo_seb currently we have no decrease factor*/

typedef int element_t;
typedef int index_t; /* i think i did this first for ctags... but why?*/

void realloc_array(varray_t_ptr array, int amount);

typedef struct _varray_t
{
    element_t* array;
    index_t size; /* #todo_seb wondering after the fact if this shouldn't represent actual number of bytes*/
    index_t capacity;
} varray_t;

varray_t_ptr create_varray()
{
    varray_t_ptr array = malloc(sizeof(varray_t));
    array->array = malloc(sizeof(element_t) * DEFAULT_SIZE);
    array->size = 0;
    array->capacity = DEFAULT_SIZE;
    return array;
}

void varray_destroy(varray_t_ptr varray)
{
    if (NULL != varray) {
        if (NULL != varray->array) {
            free(varray->array);
        }
        free(varray);
    }
}

int varray_size(varray_t_ptr varray)
{
    return varray->size;
}

void varray_add(varray_t_ptr varray, element_t element)
{
    if (varray->size == varray->capacity) {
        realloc_array(varray, varray->capacity * AUGMENT_MULTIPLE);
    }
    varray->array[varray->size] = element;
    varray->size += 1;
}

void varray_del(varray_t_ptr varray, element_t element)
{
    int found = -1;
    for (int i = 0; i < varray->size; i++) {
        if (element == varray->array[i]) {
            found = i;
            break;
        }
    }
    /* #todo_seb i might delete without knowing if here */
    if (-1 != found) {
        if (varray->array + found + 1 != varray->array + varray->size) {
            memcpy(varray->array + found,
                    varray->array + found + 1,
                    (varray->size - found - 1)*sizeof(element_t));
        }
        varray->size -= 1;
    }
}

void varray_del_at(varray_t_ptr varray, index_t index)
{
    assert(index >= varray->size);
    for (int i = index; i < varray->size-1; i++) {
        varray->array[i] = varray->array[i+1];
    }
    varray->size -= 1;
}

void realloc_array(varray_t_ptr array, index_t amount)
{
    element_t* new_allocation = realloc(array->array, amount * sizeof(element_t));
    assert(new_allocation != NULL); /* #todo_seb for now i don't want to deal with this*/
    array->array = new_allocation;
    array->capacity = amount; // #todo_seb kind of arbitrary right now considering it's ints
    if (array->size > array->capacity) array->size = array->capacity;
}

int varray_get(varray_t_ptr varray, index_t index)
{
    assert(index > 0 && index < varray->size);
    return varray->array[index];
}

void varray_set(varray_t_ptr varray, index_t index, index_t element)
{
    assert(index > 0 && index < varray->size);
    varray->array[index] = element;
}

void varray_print(varray_t_ptr varray)
{
    if (varray->size > 0)
    {
        char varray_as_string[varray->size * sizeof(element_t)]; /* #todo_seb pretty sure i'm leaking here*/
        sprintf(varray_as_string, " %d ", varray->array[0]);
        for (int i = 1; i < varray->size; i++) {
            sprintf(varray_as_string + (i * 3), ",%d ", varray->array[i]);
            /* #todo_seb clean this shit up*/
        }
        printf(varray_as_string);
    }
}
