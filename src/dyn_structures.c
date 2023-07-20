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

#define resize_stack(stack, size) (realloc(\
	stack, 2*sizeof(int) + size*sizeof(void*)\
))

void* extend(Stack *stack, int increment){

	int new_capacity = stack->capacity + increment;
	stack->capacity = new_capacity;
	return resize_stack(stack, new_capacity);	
}

void* contract(Stack *stack, int decrement){
	
	int new_capacity = stack->capacity - decrement;

	if (new_capacity < stack->items_held || new_capacity < 1){
		return stack;
	}
	stack->capacity = new_capacity;
	return resize_stack(stack, new_capacity);
}

