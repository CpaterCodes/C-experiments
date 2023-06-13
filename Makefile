compile := cc -L src/ -I headers/

main: src/main.c 
	$(compile) src/main.c

dyn_structures: src/dyn_structures.c headers/dyn_structures.h
	$(compile) src/dyn_structures.c

