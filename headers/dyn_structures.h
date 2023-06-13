
// Focusing on pointers to structs, for now

typedef struct stack {
	void *contents;
	int items_held;
	int capacity;
} Stack;

Stack new_stack (int);

void push_to (Stack, void*);

void* pop_from (Stack);

void check_inside (Stack);

