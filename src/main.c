#include <stdio.h>
#include <stdlib.h>

#define try_puts(string) (puts(string) != EOF ? EXIT_SUCCESS : EXIT_FAILURE)

typedef int result;

result main(void) {
	return try_puts("Let's 'C' what we can do!");
}

