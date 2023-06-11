compile := "cc -o main -I src/"

main: src/main.c src/try_prints.h
	$(compile) src/main.c

