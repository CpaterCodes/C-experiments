#include "../headers/dyn_structures.h"
#include<stdlib.h>
#include<stdio.h>
#include <string.h>

Stack* new_stack(int capacity) {

	Stack* stack_ptr = malloc(
		2 * sizeof(int) + capacity * sizeof(void*) 
	);
	stack_ptr->items_held = 0;
	stack_ptr->capacity = capacity;

	return stack_ptr;
}

void push_to(Stack *stack, void *last_in){
	if (stack->items_held >= stack->capacity){
		puts("Stack is full; operation refused");
		return;
	}
	stack->contents[stack->items_held] = last_in;
	++(stack->items_held);
}

void* pop_from(Stack *stack){
	if (stack->items_held == 0) {
		puts("Nothing in this stack\n");
		return NULL;
	};
	int last = stack->items_held - 1;
	unsigned long item_size = sizeof(stack->contents[last]);
	void *first_out = malloc(item_size);
	if(first_out == NULL){ 
		puts("Failure in data migration\n"); return NULL;
	}

	memcpy(first_out, stack->contents[last], item_size);

	stack->contents[last] = NULL;
	--(stack->items_held);

	return first_out;
}

