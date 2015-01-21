#include <string.h>

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
* -> int nth - Nth parameter to return.
* <- char* out - Resulting parameter.
* #######################################
*/
char* strpar(const char* str, const int nth) {
    int i, parc, delimc;
    char* out = malloc(input_limit*sizeof(char));

    for(i = 0, parc = 0, delimc = 0; i < strlen(str); i++) {
        if(str[i] == '(' || str[i] == ' ' || str[i] == ',') {
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

/* ############################################################
* Compares a char pointer with the base parameter of a command
* ------------------------------------------------------------
* -> char* cmd - Char pointer to compare with.
* -> char* input - Char pointer to user input data.
* <- int N/A - True if equal, else false.
* ############################################################
*/
int cmd_cmp(const char* cmd, const char* input) {
    return str_cmp(cmd, strpar(input, 0));
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

/* #####################################################
* Copies nth parameter of a char pointer as an integer.
* -----------------------------------------------------
* -> char* str - Input char pointer.
* -> int nth - Nth parameter to return.
* <- int N/A - Resulting integer.
* #####################################################
*/
int stripar(const char* str, const int nth) {
    return strcint(strpar(str, nth));
}
