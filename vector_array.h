#ifndef _VECTOR_ARRAY_H
#define _VECTOR_ARRAY_H

/* varray as in vector array!!!*/

/* i wanted to make a typdef of a pointer to something, thing is for my array.. this is not needed*/

typedef int element_t;
typedef int index_t;

typedef struct _varray_t varray_t;
typedef varray_t* varray_t_ptr;

varray_t_ptr create_varray();
void varray_destroy(varray_t_ptr varray);

int varray_size(varray_t_ptr varray);

void varray_add(varray_t_ptr varray, index_t element);

/* deletes the first found element*/
void varray_del(varray_t_ptr varray, index_t element);
void varray_del_at(varray_t_ptr varray, int index);

int varray_get(varray_t_ptr varray, index_t index);
void varray_set(varray_t_ptr varray, index_t index, index_t element);

/* does not work currently*/
void varray_print(varray_t_ptr varray);

#endif

