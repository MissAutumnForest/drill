#include <stdio.h>
#include <stdlib.h>

int input_limit = 80;

#include "string.c"
#include "interpreter.c"

/* #############################################
 * Code to run before entering the program loop.
 * ---------------------------------------------
 * -> N/A
 * <- N/A
 * #############################################
 */
void init() {
  printf("██████╗ ██████╗ ▀▄╗██╗     ██╗     \n");
  printf("██╔══██╗██╔══██╗▀▄║██║     ██║     \n");
  printf("██║  ██║██████╔╝██║██║     ██║     \n");
  printf("██║  ██║██╔══██╗██║██║     ██║     \n");
  printf("██████╔╝██║  ██║██║███████╗███████╗\n");
  printf("╚═════╝ ╚═╝  ╚═╝╚═╝╚══════╝╚══════╝\n");
  printf("Drill Chuck (Shell) - Alpha V0.0.1 \n");
  printf("\n");
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
