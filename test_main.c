#include <stdio.h>
#include "vector.h"

void sort (struct vector *vec);

int main ()
{
    int size;
    scanf ("%d", &size);
    struct vector *vector = vector_create (size);
    vector_init (vector);
    vector_print (vector);
    int find_size = vector_size (vector);
    printf ("vector size is: %d\n", find_size);

    add_to_tail (vector);
    vector_print (vector);
    find_size = vector_size (vector);
    printf ("vector size is: %d\n", find_size);

    remove_from_tail (vector);
    vector_print (vector);
    find_size = vector_size (vector);
    printf ("vector size is: %d\n", find_size);

    vector_destroy (vector);

    return 0;
}