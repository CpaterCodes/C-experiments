#include "../headers/dyn_structures.h"
#include<stdlib.h>
#include<stdio.h>

Stack new_stack(int capacity) {

	Stack *stack = malloc(
		(sizeof(int) * 2) + (sizeof(void*) * capacity)
	);
	stack->items_held = 0;
	stack->capacity = capacity;

	return *stack;
}

void push_to(Stack *stack, void *last_in){
	if (stack->items_held >= stack->capacity){
		puts("Stack is full; operation refused");
		return;
	}
	stack->contents[stack->items_held] = last_in;
	stack->items_held += 1;
}

int* pop_from(Stack *stack){

}

