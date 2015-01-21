/* ###########################################
* Interpret incomming commands from the user.
* -------------------------------------------
* -> int keep_running - From main method.
* <- int keep_running - To main method.
* ###########################################
*/
int interpret(int keep_running) {
  // Setup our two char pointers
  char* user_input = malloc(input_limit * sizeof(char));
  char* param = malloc(input_limit * sizeof(char));

  // Print terminal prefix.
  printf("> ");
  // Get user input and store it in our user_input pointer.
  fgets(user_input, input_limit, stdin);

  // Strip newline at the end of user input.
  user_input[strlen(user_input) - 1] = '\0';
  // Paramize our input to process as a command.
  user_input = str_paramize(user_input);

  // Check user input against various commands.
  // EXIT COMMAND
  if(cmd_cmp("exit", user_input)) {
    printf("Exiting Drill Interpreter\n");
    keep_running = 0;
  }

  // ADD COMMAND
  else if(cmd_cmp("add", user_input) || cmd_cmp("+", user_input)) {
    int add_param1 = stripar(user_input, 1);
    int add_param2 = stripar(user_input, 2);
    printf("%d\n", (add_param1 + add_param2));
  }

  // SUBTRACTION COMMAND
  else if(cmd_cmp("sub", user_input) || cmd_cmp("-", user_input)) {
    int sub_param1 = stripar(user_input, 1);
    int sub_param2 = stripar(user_input, 2);
    printf("%d\n", (sub_param1 - sub_param2));
  }

  // MULTIPLICATION COMMAND
  else if(cmd_cmp("mul", user_input) || cmd_cmp("*", user_input)) {
    int mult_param1 = stripar(user_input, 1);
    int mult_param2 = stripar(user_input, 2);
    printf("%d\n", (mult_param1 * mult_param2));
  }

  // DIVISION COMMAND
  else if(cmd_cmp("div", user_input) || cmd_cmp("/", user_input)) {
    int div_param1 = stripar(user_input, 1);
    int div_param2 = stripar(user_input, 2);
    // TEMPORARY OVERHEAD DIVISON BY ZERO PROTECTION
    if(div_param2 == 0) {
      printf("ERROR! Divison by zero detected.")
      break;
    }
    printf("%d\n", (div_param1 / div_param2));
  }

  // COMMAND NOT RECOGNIZED
  else {
    printf("\"%s\" is not recognized by Drill\n", strpar(user_input, 0));
  }

  return keep_running;
}
