#include "../headers/dyn_structures.h"
#include<stdlib.h>

Stack new_stack(int capacity) {
	void *contents_arr = malloc(sizeof(void*) * capacity);
	Stack stack = { 
		.contents=malloc(sizeof(void*) * capacity),
		.items_held=0,
		.capacity=capacity
	};
	return stack;
}

