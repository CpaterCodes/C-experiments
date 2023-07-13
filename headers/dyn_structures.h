
// Focusing on pointers to structs, for now

typedef struct stack {
	int items_held;
	int capacity;
	int *contents[];
} Stack;

Stack new_stack (int);

void push_to (Stack*, int*);

void* pop_from (Stack*);

void check_inside (Stack*);

