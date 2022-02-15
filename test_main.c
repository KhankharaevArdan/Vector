#include "vector.h"

void printElem(void* x)
{
	printf("%d ", *((int*) x));
}

int main()
{
	methods* m = (methods*)malloc(sizeof(methods));
	Container* vector = vector_create(m);
	printf("We have created the vector and now we want to initialize it.\n");

	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	(m->init)(vector, a, 10, sizeof(int));
	printf("That's it:\n");
	(m->print)(vector, printElem);

	/*int zero = 0;
	printf("Now we are going to add element 0 to the front\n");
	(m->pushFront)(vector, &zero);
	printf("That's it:\n");
	(m->print)(vector, printElem);

	int* front = (m->popFront)(vector);
	printf("%d was removed from the front.\n", *front);
	printf("That's it:\n");
	(m->print)(vector, printElem);

    */

	int ten = 10;
	printf("Now we are going to add element 10 to the back\n");
	(m->pushBack)(vector, &ten);
	printf("That's it:\n");
	(m->print)(vector, printElem);

	int* back = (m->popBack)(vector);
	printf("%d was removed from the back.\n", *back);
	printf("That's it:\n");
	(m->print)(vector, printElem);

	printf("Which node do you want to find?\n");
	int index;
	scanf("%d", &index);
	Node* node = (m->getNode)(vector, index);
	printf("That's it: %d\n", *((int*)(node->data)));

    /*

	printf("Where an what do you want to push?\n");
	int where; int what;
	scanf("%d %d", &where, &what);
	(m->push)(vector, where, &what);
	printf("That's it:\n");
	(m->print)(vector, printElem);

	printf("What do you want to pop?\n");
	int pop_what;
	scanf("%d", &pop_what);
	int* answer = (m->pop)(vector, pop_what);
	printf("That's it: %d\n", *answer);
	(m->print)(vector, printElem);
    */

	(m->delete)(vector);

	printf("We have deleted the vector.\n");

	return 0;
}