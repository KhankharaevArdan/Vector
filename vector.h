#ifndef VECTOR
#define VECTOR
#include <stdio.h>
#include <stdlib.h>

struct vector
{
    int* head_;
    int size_;
};

struct vector* vector_create (int size);
int vector_size (struct vector *vector);
void vector_init (struct vector *vector);
void add_to_tail (struct vector *vector);
void remove_from_tail (struct vector *vector);
int find_elem (struct vector* vector, int number);
void vector_print (const struct vector *vector);
void vector_destroy (struct vector* vector);

#endif