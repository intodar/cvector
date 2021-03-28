#include <stdio.h>

#include "vector.h"

int main(void)
{
    vector_t vector = NULL;
    
    {
        vector = vector_construct(sizeof(int));

        int a = 1000;

        vector_insert(vector, &a, 0);

        printf("0 item : %d\n", *((int *) vector_at(vector, 0)));

        vector_destruct(&vector);

        vector = NULL;
    }

    {
        vector = vector_construct(sizeof(long long));

        for (size_t i = 0; i < 10; i++)
        {
            vector_insert(vector, &i, vector_size(vector));
        }

        for (size_t i = 0; i < 5; i++)
        {
            vector_erase(vector, i);
        }

        for (size_t i = 0; i < vector_size(vector); i++)
        {
            printf("%ld item : %lld\n", i, *((long long *) vector_at(vector, i)));
        }

        vector_clear(vector);

        vector_destruct(&vector);

        vector = NULL;
    }

    return 0;
}
