all:
	gcc src/main.c -o build/main

static:
	gcc -static src/main.c -o build/drill
