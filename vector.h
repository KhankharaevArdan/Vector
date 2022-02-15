#ifndef VECTOR
#define VECTOR
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    size_t num;
    void* data;
} Node;

typedef struct Vector
{
    Node* first;
    size_t size;
} Vector;

typedef struct Container
{
	Vector vector;
} Container;

typedef struct methods
{
	void (*init)(void*, void*, size_t, size_t);
	void (*delete)(void*);

	void (*pushFront)(void*, void*);
	void* (*popFront)(void*);
	void (*pushBack)(void*, void*);
	void* (*popBack)(void*);
	void (*push)(void*, size_t, void*);
	void* (*pop)(void*, size_t);
	Node* (*getNode)(void*, size_t);
	void (*print)(void*, void (*printElem)(void*));
} methods;

Vector* vector_create(methods* m);
void vector_pushFront(Vector* vector, void* data);
void* vector_popFront(Vector* vector);
void vector_pushBack(Vector* vector, void* data);
void* vector_popBack(Vector* vector);
void vector_push(Vector* vector, size_t index, void* data);
void* vector_pop(Vector* vector, size_t index);
Node* vector_getNode(Vector* vector, size_t index);
void vector_init(Vector* vector, void* arr, size_t n, size_t size);
void vector_delete(Vector* vector);
void vector_print(Vector* vector, void (*printElem)(void*));

#endif