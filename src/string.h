#include <string.h>

#define INPUT_LIMIT 80

typedef struct {
  char* data;
  int length;
} string;

string String(char* str) {
  string res = {str, strlen(str)};
  return res;
}

string string_snl(string str) {
  if(str.data[str.length-1] == '\n') {
    str.data[str.length-1] = 0;
  }

  return str;
}

string string_read() {
  char* result = malloc(INPUT_LIMIT);
  fgets(result, INPUT_LIMIT, stdin);

  return string_snl(String(result));
}

int string_cmp(string str1, string str2) {
  int len = str1.length < str2.length ? str1.length : str2.length;

  return memcmp(str1.data, str2.data, len) == 0;
}
