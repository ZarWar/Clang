all: run
debug:
	strDebug.pl --file=./debug.c
compile: debug
	gcc -o ./debug_O ./debug.c
run: compile
	./debug_O
