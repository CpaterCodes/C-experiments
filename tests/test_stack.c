#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../tests/test_stack.h"
#include "../headers/stack.h"

void test_stack_init(void) {
	puts("Testing stack init...\n");

	Stack example_stack = *new_stack(10);
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
	puts("Init Testing: Complete\n");
}

void test_push(void){

	Stack* stack_for_push = new_stack(2);
	Point point_a = {.x=10, .y=20}; 
	Point point_b = {.x=30, .y=60};
	Point point_c = {.x=90, .y=180};

	puts("Testing stack push...");
	push_to(stack_for_push, &point_a);
	assert(stack_for_push->items_held == 1);
	assert(stack_for_push->contents[0] == &point_a);

	push_to(stack_for_push, &point_b);
	assert(stack_for_push->items_held == 2);
	assert(stack_for_push->contents[1] == &point_b);

	puts("Pushed! Now to try another... this shouldn't be allowed");
	push_to(stack_for_push, &point_c);
	assert(stack_for_push->items_held != 3);
	puts("Push Testing: Complete\n");
}

void test_pop(void){
	Stack* stack_for_pop = new_stack(4);
	puts("Should safely return nothing; empty");
	assert(pop_from(stack_for_pop) == NULL);

	Point point_a = {.x=0, .y=0}; push_to(stack_for_pop, &point_a);
	Point point_b = {.x=5, .y=0}; push_to(stack_for_pop, &point_b);
	Point point_c = {.x=0, .y=5}; push_to(stack_for_pop, &point_c);
	Point point_d = {.x=5, .y=5}; push_to(stack_for_pop, &point_d);

	puts("Stack should now have 4 points. Testing...");
	assert(stack_for_pop->items_held == 4);
	assert(stack_for_pop->contents[3] == &point_d);

	Point* popped = pop_from(stack_for_pop);

	puts("Checking new item count... should be 3");
	assert(stack_for_pop->items_held == 3);
	puts("Checking details of popped item...");
	assert(stack_for_pop->contents[3] != &point_d);

	puts("Checking that stack can be pushed to after popping");
	push_to(stack_for_pop, &point_b);
	assert(stack_for_pop->contents[3] == &point_b);
	puts("Pop testing: Complete\n");
}

void test_extend(void){
	puts("Initialising with a capacity of 1");

	Stack* undersized_stack = new_stack(1);
	Point some_point = {.x=1, .y=1};
	Point surplus_point = {.x=2, .y=2};
	
	puts("Should accept the second item once extended...");
	undersized_stack = extend(undersized_stack, 1);
	push_to(undersized_stack, &some_point);
	push_to(undersized_stack, &surplus_point);
	assert(undersized_stack->items_held == 2);
	puts("Extend Testing: Complete\n");
}

void test_contract(void){
	Stack* oversized_stack = new_stack(3);

	puts("Should contract assuming there is empty space to do so");
	oversized_stack = contract(oversized_stack, 1);
	assert(oversized_stack->capacity == 2);

	puts("Should not contract to 0");
	oversized_stack = contract(oversized_stack, 2);
	assert(oversized_stack->capacity == 2);

	Point some_point = { .x=2, .y=4};
	Point surplus_point = {.x=4, .y=8};
	push_to(oversized_stack, &some_point);
	push_to(oversized_stack, &some_point);

	puts("Should not be allowed to contract below current fill");
	oversized_stack = contract(oversized_stack, 1);
	assert(oversized_stack->capacity == 2);
	puts("Contract Testing: Complete\n");
}

char* view_point(Point* point){
	return "...";
}

void test_view(void){
	puts("Should format stack, given a means to format members");
	Stack* stack = new_stack(3);
	Point a = {.x=1, .y=1}; Point b = {.x = 2, .y = 2};
	push_to(stack, &a); push_to(stack, &b);
	char* (*viewer) (void*) = (view_func) &view_point; 
	char* stack_view = view_stack(stack, viewer);

	assert(
		strcmp(stack_view, "[{x: 1,y: 1}, {x: 2,y: 2}]") == 0
	);
}

void test_stack(){
	test_stack_init();
	test_push();
	test_pop();
	test_extend();
	test_contract();
	test_view();
}

