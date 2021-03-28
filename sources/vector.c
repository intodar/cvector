#include <stdlib.h>
#include <string.h>

#include "vector.h"

struct vector
{
    size_t _nmemb;
    size_t _size;
    void *ptr;
};

vector_t vector_construct(size_t memb_size)
{
// 	vector_t new_vec = (vector_t) malloc(sizeof(struct vector));
//     if  (memb_size == 0)
//         return NULL;

    vector_t new_vector = NULL;
    new_vector = (vector_t) malloc(sizeof(struct vector));

    if (new_vector == NULL)
        return NULL;

    new_vector->ptr = NULL;
    new_vector->_nmemb = 0;
    new_vector->_size = memb_size;

    return new_vector;
}

void *const vector_at(vector_t vector, size_t index)
{
    if (vector == NULL)
        return NULL;

    if (index >= vector->_nmemb)
        return NULL;

    return (((char *) vector->ptr) + index * vector->_size);
}

int vector_is_empty(vector_t const vector)
{
    if (vector == NULL)
        return 0;

    if (vector->_nmemb == 0)
        return 1;
    else
        return 0;
}

size_t vector_size(vector_t const vector)
{
    if (vector == NULL)
        return EXIT_FAILURE;

    return vector->_nmemb;
}

int vector_reserve(vector_t const vector, size_t new_nmemb)
{
    if (vector == NULL)
        return EXIT_FAILURE;

    if (vector->_size == 0)
        return EXIT_FAILURE;

    void *buffer = (void *) realloc(vector->ptr, new_nmemb * vector->_size);

    if (buffer == NULL)
        vector->_nmemb = 0;
    else
        vector->_nmemb = new_nmemb;

    vector->ptr = buffer;

    return EXIT_SUCCESS;
}

int vector_clear(vector_t vector)
{
    if (vector == NULL)
        return EXIT_FAILURE;

    free(vector->ptr);
    vector->ptr = NULL;

    vector->_nmemb = 0;

    return EXIT_SUCCESS;
}

int vector_insert(const vector_t vector, void *elem, size_t index)
{
    if (vector == NULL)
        return EXIT_FAILURE;

    if (index > vector->_nmemb)
        return EXIT_FAILURE;

    if (vector_reserve(vector, vector->_nmemb + 1) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    if (vector->_nmemb == 0)
        return EXIT_FAILURE;

    for (size_t i = vector->_nmemb - 1; i > index; i--)
    {
        memcpy(((char *) vector->ptr) + i * vector->_size, 
                ((char *) vector->ptr) + (i - 1) * vector->_size, 
                vector->_size);
    }

    memcpy(((char *) vector->ptr) + index * vector->_size, 
            elem, 
            vector->_size);

    return EXIT_SUCCESS;
}

int vector_erase(const vector_t vector, size_t index)
{
    if (vector == NULL)
        return EXIT_FAILURE;

    if (vector->_nmemb == 0)
        return EXIT_FAILURE;

    if (index >= vector->_nmemb)
        return EXIT_FAILURE;

    for (size_t i = index; i < vector->_nmemb - 1; i++)
    {
        memcpy(((char *) vector->ptr) + i * vector->_size, 
                ((char *) vector->ptr) + (i + 1) * vector->_size, 
                vector->_size);
    }

    vector->_nmemb--;

    if (vector->_nmemb == 0)
    {
        free(vector->ptr);
        vector->ptr = NULL;
    }

    return EXIT_SUCCESS;
}

int vector_destruct(vector_t *vector)
{
    if (vector == NULL)
        return EXIT_FAILURE;

    if (*vector == NULL)
        return EXIT_SUCCESS;

    if ((*vector)->ptr != NULL)
    {
        free((*vector)->ptr);
    }
    (*vector)->_nmemb = 0;
    (*vector)->_size = 0;

    free(*vector);

    (*vector) = NULL;

    return EXIT_SUCCESS;
}
