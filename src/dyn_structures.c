#include "../headers/dyn_structures.h"
#include<stdlib.h>

Stack new_stack(int capacity) {

	Stack *stack = malloc(
		(sizeof(int) * 2) + (sizeof(int*) * capacity)
	);
	stack->items_held = 0;
	stack->capacity = capacity;

	return *stack;
}

