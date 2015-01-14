/* ###########################################
 * Get nth parameter (if any) from user input.
 */
string get_params(string str, int param) {
  return str_paramize(str);
}

/* ###########################################
 * Interpret incomming commands from the user.
 * -------------------------------------------
 * -> int keep_running - From main method.
 * <- int keep_running - To main method.
 * ###########################################
 */
int interpret(int keep_running) {
  printf("> ");
  string user_input = str_read(100);
  string params = get_params(user_input, 0);

  if(str_cmp(params, String("exit"))) {
    printf("Exiting Drill Interpreter\n");
    keep_running = 0;
  }
  else if (str_cmp(params, String("hello"))) {
    printf("HI!\n");
  }
  else {
    printf("\"%s\" is not recognized by Drill\n", params.data);
  }

  return keep_running;
}
