#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../headers/try_prints.h"
#include "../headers/dyn_structures.h"

typedef int result;

result main(void) {
	try_puts(
			"Hello World! We're testing data structures", 
			{return EXIT_SUCCESS;},
			{return EXIT_FAILURE;}
	);
}

