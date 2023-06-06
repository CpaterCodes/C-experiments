
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int did_put = puts("Let's 'C' what we can do!");
	return did_put != EOF ? EXIT_SUCCESS : EXIT_FAILURE;
}

