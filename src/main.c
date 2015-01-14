#include <stdio.h>
#include <stdlib.h>

#include "string.h"
#include "interpreter.h"

void init() {
  printf("Drill Interpreter V0.0.1 \n\n");
}

int main(int argc, char* argv[]) {
  int keep_running = 1;

  init();

  while(interpret(keep_running));
}
