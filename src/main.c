#include <stdio.h>
#include <stdlib.h>
#include <try_prints.h>

typedef int result;

result main(void) {
	try_puts(
		"Let's 'C' what we can do!",
		{return EXIT_SUCCESS;},
		{return EXIT_FAILURE;}
	);
}

