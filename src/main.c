#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <try_prints.h>
#include <dyn_structures.h>


typedef int result;

void test_stack(void) {
	Stack example_stack = new_stack(10);
	assert(1 == 1);
}

result main(void) {
	try_puts(
		"Let's 'C' what we can 'make'!",
		{return EXIT_SUCCESS;},
		{return EXIT_FAILURE;}
	);
}

