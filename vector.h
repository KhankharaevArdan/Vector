#ifndef VECTOR
#define VECTOR
#include <stdio.h>
#include <stdlib.h>

typedef struct methods
{
    void (*init)(void*, void*, size_t, size_t);
    void (*delete)(void*);
    void (*pushBack)(void*, void*);
    void* (*popBack)(void*);
    void (*print)(void*, void (*printElem)(void*));
} methods;

typedef struct Container
{
    methods* m;
} Container;

Container* vector_create();
Container* List_create(methods* m);
void vector_setValue(Container* container, size_t index, void* data);
void* vector_getValue(Container* container, size_t index);
void List_pushFront(Container* container, void* data);
void* List_popFront(Container* container);
void List_push(Container* container, size_t index, void* data);
void* List_pop(Container* container, size_t index);
//Node* List_getNode(Container* container, size_t index);

#endif