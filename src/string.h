#include <string.h>

#define INPUT_LIMIT 80

/* #######################
 * Struct for string type.
 * -----------------------
 * -> N/A
 * <- N/A
 * #######################
 */
typedef struct {
  char* data;
  int length;
} string;

/* ######################################
 * Create a new string from char pointer.
 * --------------------------------------
 * -> char* str - Char pointer.
 * <- string res - Resulting string.
 * ######################################
 */
string String(char* str) {
  string res = {str, strlen(str)};
  return res;
}

/* ################################################
 * remove parenthesis and replace them with a comma
 * and remove the last comma.
 * ------------------------------------------------
 * -> string str - String to be paramized.
 * <- string str - Resulting paramized string.
 * ################################################
 */
string str_paramize(string str) {
  int i;
  int has_comma = 0;

  // Replace all parenthesis with a comma.
  for(i = 0; i < str.length; i++) {
    if(str.data[i] == '(' || str.data[i] == ')') {
      str.data[i] = ',';
    }
  }

  // Check if string even has a comma.
  for(i = 0; i < str.length; i++) {
    if(str.data[i] == ',') {
      has_comma = 1;
      break;
    }
  }

  // Remove trailing comma and all character after it.
  // This only happens if the string contains at least one comma.
  if(has_comma) {
    for(i = str.length; i > 0; i--) {
      if(str.data[i] != ','){
        str.data[i] = 0;
      } else {
        str.data[i] = 0;
        break;
      }
    }
  }

  return str;
}

/* ########################
 * Remove trailing newline.
 * ------------------------
 * -> string str - String.
 * <- string str - Result.
 * ########################
 */
string str_rnl(string str) {
  if(str.data[str.length-1] == '\n') {
    str.data[str.length-1] = '\0';
  }

  return str;
}

/* ####################################################
 * Reads characters from user, then converts to string.
 * ----------------------------------------------------
 * -> N/A
 * <- string N/A - Resulting string.
 * ####################################################
 */
string str_read() {
  char* result = malloc(INPUT_LIMIT);
  fgets(result, INPUT_LIMIT, stdin);

  return str_rnl(String(result));
}

/* ##############################################
 * Compares two strings to see if they are equal.
 * ----------------------------------------------
 * -> string str1 - First string.
 * -> string str2 - Second string.
 * <- int N/A - True if equal, else false.
 * ##############################################
 */
int str_cmp(string str1, string str2) {
  int len = str1.length < str2.length ? str1.length : str2.length;

  return memcmp(str1.data, str2.data, len) == 0;
}
