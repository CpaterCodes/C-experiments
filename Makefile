
compiler := gcc
options := -I headers/ -c
obj_output := -o objects/

main: objects/main.o objects/dyn_structures.o
	$(compiler) -o main objects/main.o objects/dyn_structures.o 

objects/main.o: src/main.c
	$(compiler) $(options) src/main.c -o objects/main.o

objects/dyn_structures.o: src/dyn_structures.c headers/dyn_structures.h
	$(compiler) $(options) src/dyn_structures.c -o objects/dyn_structures.o
	
