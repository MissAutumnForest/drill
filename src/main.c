#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * ### NOTE ###
 * Currently just repeats what you enter.
 */

void init() {
  printf("Drill Interpreter V0.0.1 \n\n");
}

char* read_string(length) {
  char input[length];
  char* result = malloc(sizeof(input));

  fgets(input, sizeof(input), stdin);
  strcpy(result, input);

  return result;
}

void main() {
  int run = 1;

  init();

  while(run){
    printf("> ");
    char* user = read_string(100);

    printf("\nYou entered: %s", user);
  }
}
