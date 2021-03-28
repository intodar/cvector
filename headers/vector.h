#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdlib.h>

typedef struct vector *vector_t;

vector_t vector_construct(size_t memb_size);

void *const vector_at(vector_t vector, size_t index);

int vector_is_empty(vector_t const vector);

size_t vector_size(vector_t const vector);

int vector_reserve(vector_t const vector, size_t new_nmemb);

int vector_clear(vector_t vector);

int vector_insert(vector_t vector, void *elem, size_t index);

int vector_erase(const vector_t vector, size_t index);

int vector_destruct(vector_t *vector);

#endif // __VECTOR_H__