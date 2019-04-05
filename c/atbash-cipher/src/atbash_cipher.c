#include "atbash_cipher.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static char flip(const char c) {
    if (isdigit(c)) {
        return c;
    }
    return 'z' - tolower(c) + 'a';
}

static char* atbash(const char * const input, const int group) {
    char *result = malloc(2 * strlen(input));
    int len = 0;
    int count = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (!isalnum(input[i])) {
            continue;
        }

        result[len++] = flip(input[i]);
        if (group > 0 && ++count == group) {
            result[len++] = ' ';
            count = 0;
        }
    }

    if (result[len-1] == ' ') {
        result[len-1] = '\0';
    }

    result[len] = '\0';

    return result;
}

char* atbash_encode(const char * const input) {
    return atbash(input, 5);
}

char* atbash_decode(const char * const input) {
    return atbash(input, 0);
}

