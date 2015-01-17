static int input_limit = 80;
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
  if(str_cmp(strpar(user_input, param, 0), "exit")) {
    printf("Exiting Drill Interpreter\n");
    keep_running = 0;
  }

  // ADD COMMAND
  else if(str_cmp(strpar(user_input, param, 0), "add")) {
    int add_param1 = strcint(strpar(user_input, param, 1));
    int add_param2 = strcint(strpar(user_input, param, 2));
    printf("%d\n", (add_param1 + add_param2));
  }

  // SUB COMMAND
  else if(str_cmp(strpar(user_input, param, 0), "sub")) {
    int sub_param1 = strcint(strpar(user_input, param, 1));
    int sub_param2 = strcint(strpar(user_input, param, 2));
    printf("%d\n", (sub_param1 - sub_param2));
  }
  // MULT COMMAND
  else if(str_cmp(strpar(user_input, param, 0), "mult")) {
    int mult_param1 = strcint(strpar(user_input, param, 1));
    int mult_param2 = strcint(strpar(user_input, param, 2));
    printf("%d\n", (mult_param1 * mult_param2));
  }
  // DIV COMMAND
  else if(str_cmp(strpar(user_input, param, 0), "div")) {
    int div_param1 = strcint(strpar(user_input, param, 1));
    int div_param2 = strcint(strpar(user_input, param, 2));
    printf("%d\n", (div_param1 / div_param2));
  }
  // DIDN'T RECOGNIZE THE COMMAND
  else {
    printf("\"%s\" is not recognized by Drill\n", strpar(user_input, param, 0));
  }

  return keep_running;
}
