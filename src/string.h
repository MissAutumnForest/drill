#include <string.h>

/* ################################################
 * Remove parenthesis and replace them with a comma
 * and remove the last comma.
 * ------------------------------------------------
 * -> char str - String to be paramized.
 * <- char str - Resulting paramized string.
 * ################################################
 */
char* str_paramize(char* str) {
  int i;
  int has_comma = 0;

  // Replace all parenthesis with a comma.
  for(i = 0; i < strlen(str); i++) {
    if(str[i] == '(' || str[i] == ')') {
      str[i] = ',';
    }
  }

  // Check if string even has a comma.
  for(i = 0; i < strlen(str); i++) {
    if(str[i] == ',') {
      has_comma = 1;
      break;
    }
  }

  // Remove trailing comma and all character after it.
  // This only happens if the string contains at least one comma.
  if(has_comma) {
    for(i = strlen(str); i > 0; i--) {
      if(str[i] == ',') {
        str[i+1] = '\0';
        return str;
      }
    }
  }

  return str;
}

/* ########################################
 * Compares two char pointers for equality.
 * ----------------------------------------
 * -> char* str1 - First pointer.
 * -> char* str2 - Second pointer.
 * <- int N/A - True if equal, else false.
 * ########################################
 */
int str_cmp(const char* str1, const char* str2) {
  if(strlen(str1) != strlen(str2)) return 0;
  return memcmp(str1, str2, strlen(str1)) == 0;
}

/* #######################################
 * Copies nth parameter of a char pointer.
 * ---------------------------------------
 * -> char* str - Input char pointer.
 * -> char* out - Pointer to copy to.
 * -> int nth - Nth parameter to return.
 * <- char* out - Pointer copied to.
 * #######################################
 */
char* strpar(const char* str, char* out, const int nth) {
  int i, parc, delimc;

  for(i = 0, parc = 0, delimc = 0; i < strlen(str); i++) {
    if(str[i] == ',') {
      if(delimc == nth) {
        out[parc] = '\0';
        return out;
      }

      delimc++;
      i++;
      parc = 0;
    }
    out[parc] = str[i];
    parc++;
  }
  return out;
}

/* ############################################
 * Convert a char pointer into an integer type.
 * --------------------------------------------
 * -> char* str - char* to be converted.
 * <- long res - Resulting integer.
 * ############################################
 */
long strcint(const char* str) {
  int num;
  char* ptr;
  return strtol(str, &ptr, 10);
}
