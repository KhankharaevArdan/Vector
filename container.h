#ifndef VECTOR
#define VECTOR

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct methods
{
    void (*init)(void*, void*, size_t, size_t);
    void (*delete)(void*);
    void (*pushBack)(void*, void*);
    void* (*popBack)(void*);
    void (*print)(void*, void (*printElem)(void*));
    void (*bubbleSort)(void*, bool (*compType)(void*, void*));
} methods;

typedef struct Container
{
    methods* m;
} Container;

Container* vector_create();
Container* List_create();
void vector_setValue(Container* container, size_t index, void* data);
void* vector_getValue(Container* container, size_t index);


#endif