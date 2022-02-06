#include "vector.h"

struct vector* vector_create (int size)
{
    struct vector* vector = (struct vector*) malloc (sizeof(struct vector));
    vector->head_ = (int*) malloc (size * sizeof(int));
    vector->size_ = size;
    return vector;
}

int vector_size (struct vector *vector)
{
    return vector->size_;
}

void vector_init (struct vector *vector)
{
    for (int i = 0; i < vector->size_; ++i)
        scanf ("%d", (vector->head_) + i);
}

void add_to_tail (struct vector *vector)
{
    vector->head_ = (int*) realloc (vector->head_, vector->size_ + 1);
    vector->size_ = vector->size_ + 1;
    printf ("new element: ");
    scanf ("%d", (vector->head_) + (vector->size_) - 1);
}

void remove_from_tail (struct vector *vector)
{
    vector->head_[vector->size_ - 1] = -1;
    vector->size_ = vector->size_ - 1;
    vector->head_ = (int*) realloc (vector->head_, vector->size_ - 1);
}

int find_elem (struct vector* vector, int number)
{
    if (number < vector->size_)
        return vector->head_ [number];
    else    
        return -1;
}

void vector_print (const struct vector *vector)
{
    printf ("vector elements: ");
    for (int i = 0; i < vector->size_; ++i)
        printf ("%d ", vector->head_[i]);
    printf ("\n");
}

void vector_destroy (struct vector* vector)
{
    free (vector->head_);
    vector->size_ = 0;
    free (vector);
}
