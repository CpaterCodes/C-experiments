#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../headers/try_prints.h"
#include "../headers/dyn_structures.h"


typedef int result;

void test_stack_init(void) {
	puts("Testing our stack...\n");

	Stack example_stack = new_stack(10);
	assert(example_stack.capacity == 10);
	puts("It will initialise with a given length passed to constructor.");

	assert(example_stack.items_held == 0);
	puts("It will initialise with an items held value of 0.");
	
	printf("Size: %lu\n", sizeof(example_stack.contents[0]));
}

result main(void) {
	test_stack_init();
	try_puts(
		"\nLet's 'C' what we can 'make'!",
		{return EXIT_SUCCESS;},
		{return EXIT_FAILURE;}
	);

}

