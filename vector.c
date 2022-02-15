#include "Vector.h"

Vector* vector_create(methods* m)
{
	Vector* vector = (Vector*)malloc(sizeof(Vector));
	vector->size = 0;
	vector->first = NULL;

	m->pushFront = vector_pushFront;
	m->popFront = vector_popFront;
	m->pushBack = vector_pushBack;
	m->popBack = vector_popBack;
	m->push = vector_push;
	m->pop = vector_pop;
	m->getNode = vector_getNode;
    m->init = vector_init;
	m->delete = vector_delete;
	m->print = vector_print;

	return vector;
}

void vector_pushFront(Vector* vector, void* data)
{
	size_t size = vector->size + 1;
    Node* tmp = (Node*)malloc(size * sizeof(Node));
    Node* elem = (Node*)malloc(sizeof(Node));
	tmp[0].data = data;
    tmp[0].num = 0;
	for (size_t i = 1; i < size; i++) 
    {
		elem = vector->first + (i - 1) * sizeof(Node*);
        tmp[i].data = elem->data;
        tmp[i].num = i;
    }
    vector->size = size;
    vector->first = tmp;
}

void* vector_popFront(Vector* vector)
{
    Node* elem = (Node*)malloc(sizeof(Node));
    Node* tmp_elem = (Node*)malloc((vector->size - 1) * sizeof(Node));
    void* tmp;
    elem = vector->first;
    tmp = elem->data;
    for (size_t i = 1; i < vector->size; i++) 
    {
		elem = vector->first + (i) * sizeof(Node*);
        tmp_elem[i - 1].data = elem->data;
        tmp_elem[i - 1].num = i - 1;
    }
    --vector->size;
    vector->first = tmp_elem;
    return tmp;
}

void vector_pushBack(Vector* vector, void* data)
{
    ++(vector->size);
    Node* elem = (Node*)malloc(sizeof(Node));
    if (vector->first == NULL)
    {
        elem->data = data;
        elem->num = 0;
        vector->first = elem;
    }
    else
    {
        elem = vector->first + (vector->size - 1) * sizeof(Node*);
        elem->data = data;
        elem->num = vector->size - 1;
    }
}

void* vector_popBack(Vector* vector)
{
    Node* elem = (Node*)malloc(sizeof(Node));
    void* tmp;
    elem = vector->first + (vector->size - 1) * sizeof(Node*);
    tmp = elem->data;
    elem = NULL;
    --(vector->size);
    return tmp;
}

void vector_push(Vector* vector, size_t index, void* data)
{
    size_t size = vector->size + 1;
	Node* elem = (Node*)malloc(size * sizeof(Node));
	vector->size = size;
    for (size_t i = 0; i < size; i++)
		elem[i].num = i;
	for (size_t i = 0; i < index; i++) 
		elem[i].data = vector->first[i].data;
	elem[index].data = data;
	for (size_t i = index; i < size; i++) 
		elem[i].data = vector->first[i - 1].data;
	free(vector->first);
	vector->first = elem;
}

Node* vector_getNode(Vector* vector, size_t index)
{
	return vector->first + (index) * sizeof(Node*);
}

void* vector_pop(Vector* vector, size_t index)
{
    Node* elem = (Node*)malloc(sizeof(Node));
    void* tmp;
    elem = vector_getNode(vector, index);
    tmp = elem->data;
    for (size_t i = index; i < vector->size; i++) 
	    vector->first[i].data = vector->first[i + 1].data;
    --vector->size;
    return tmp;
}

void vector_init(Vector* vector, void* arr, size_t n, size_t size)
{
    size_t i = 0;
	if (arr == NULL)
		exit(6);
	if (vector == NULL)
		exit(7);
	while (i < n)
	{   
		vector_pushBack(vector, (char*)arr + i * size);
		i++;
	}
}

void vector_delete(Vector* vector)
{
    Node* elem = (Node*)malloc(sizeof(Node));
    int i = 0;
	while (elem)
	{
        elem = vector_getNode(vector, i);
        printf ("%ld) ", elem->num);
        free(elem);
        ++i;
	}
	free(vector);
	vector = NULL;
}

void vector_print(Vector* vector, void (*printElem)(void*))
{
    Node* elem = (Node*)malloc(sizeof(Node));
    size_t i = 0;
	while ((elem) && (i < vector->size))
	{
        elem = vector_getNode(vector, i);
		printElem(elem->data);
        ++i;
	}
	printf("\n");
}


