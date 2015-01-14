#include <stdio.h>
#include <stdlib.h>

#include "string.h"
#include "interpreter.h"

/* #############################################
 * Code to run before entering the program loop.
 * ---------------------------------------------
 * -> N/A
 * <- N/A
 * #############################################
 */
void init() {
  printf("Drill Interpreter V0.0.1 \n\n");
}

/* ###############################
 * The main method of the program.
 * -------------------------------
 * -> int argc - Argument Count.
 * -> char* argv[] - Arguments.
 * <- N/A
 * ###############################
 */
int main(int argc, char* argv[]) {
  int keep_running = 1;

  init();

  while(interpret(keep_running));
}
