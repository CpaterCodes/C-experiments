
// Focusing on pointers to structs, for now

typedef struct stack {
	int items_held;
	int capacity;
	void *contents[];
} Stack;

Stack* new_stack(int);

void push_to(Stack*, void*);

void* pop_from(Stack*);

void* extend(Stack*, int);

void* contract(Stack*, int);

void check_inside(Stack*);

