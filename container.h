#ifndef CONTAINER_H
#define CONTAINER_H

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

Container* List_create();
Container* vector_create();

#endif // CONTAINER_H