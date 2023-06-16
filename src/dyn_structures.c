#include<dyn_structures.h>
#include<stdlib.h>

Stack new_stack(int capacity) {
	Stack stack = { 
		.contents=malloc(sizeof(void*) * capacity),
		.items_held=0,
		.capacity=capacity
	};
	return stack;
}

