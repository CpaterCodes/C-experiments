#include <stdlib.h>

#define try_puts(string, happy_path, exception_path) {\
	if (puts(string) != EOF) happy_path else exception_path}

#define try_printf(template, input, happy_path, exception_path) {\
	if (printf(template, input) >= 0) happy_path else exception_path}

