int interpret(int keep_running) {
  string cmd_exit = String("exit");

  printf("> ");
  string user_input = string_read(100);

  if(string_cmp(user_input, cmd_exit)) {
    printf("Exiting Drill Interpreter\n");
    keep_running = 0;
  } else {
    printf("\"%s\" is not recognized by Drill\n", user_input.data);
  }

  return keep_running;
}
