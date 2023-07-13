#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../headers/try_prints.h"
#include "../headers/dyn_structures.h"


typedef int result;

void test_stack_init(void) {
	puts("Testing stack init...\n");

	Stack example_stack = new_stack(10);
	assert(example_stack.capacity == 10);
	puts("It will initialise with a given length passed to constructor.");

	assert(example_stack.items_held == 0);
	puts("It will initialise with an items held value of 0.");
	
	int stack_size = 0;
	int element_size = sizeof(example_stack.contents[0]);
	for (int i = 0; i < example_stack.capacity; i++){
		stack_size += element_size;
	}
	printf("Size total: %d\n", stack_size);
	printf("Size per element: %d\n", element_size);
	assert(stack_size / element_size == example_stack.capacity);
}

typedef struct Point {
	int x;
	int y;
} Point;

void test_push(void){

	Stack stack_for_push = new_stack(1);
	Point point_a = {.x=10, .y=20}; 
	Point point_b = {.x=30, .y=60};

	puts("Testing stack push...\n");
	push_to(&stack_for_push, &point_a);
	assert(stack_for_push.items_held == 1);
	assert(stack_for_push.contents[0] == &point_a);

	puts("Pushed! Now to try another... this shouldn't be allowed");
	push_to(&stack_for_push, &point_b);
	assert(stack_for_push.items_held == 1);
	assert(stack_for_push.contents[1] != &point_b);
}
void test_pop(void){}

result main(void) {
	test_stack_init();
	test_push();
	test_pop();
	return EXIT_SUCCESS;

}

