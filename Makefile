
compiler := gcc

main: objects/*.o
	$(compiler) $^ -o $@

objects/%.o: src/%.c
	$(compiler) -c $< -o $@

