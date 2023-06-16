
cc := gcc
options := -L src/ -I headers/ -c
obj_output := -o objects/

main: objects/main.o objects/dyn_structures.o
	$(cc) -o main objects/main.o objects/dyn_structures.o 

objects/main.o: src/main.c
	$(cc) $(options) src/main.c -o objects/main.o

objects/dyn_structures.o: src/dyn_structures.c headers/dyn_structures.h
	$(cc) $(options) src/dyn_structures.c -o objects/dyn_structures.o
	
