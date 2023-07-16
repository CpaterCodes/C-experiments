
compiler := gcc

main: objects/*.o
	$(compiler) $^ -o $@

test: tests/*.c src/dyn_structures.c
	$(compiler) -o $@ $^

objects/%.o: src/%.c
	$(compiler) -c $< -o $@

