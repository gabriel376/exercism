#include "phone_number.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ERROR "0000000000"
#define PHONE_LEN 10
#define MAX_LEN PHONE_LEN + 1

static char* error(char *data) {
    sprintf(data, "%s", ERROR);
    return data;
}

static int check_char(char actual, const char *expected) {
    while (*expected)
        if (actual == *expected++)
            return 1;
    return 0;
}

char* phone_number_clean(const char *phone) {
    char *result = calloc(MAX_LEN + 1, sizeof(char));
    char chr;
    int len = 0;

    for (int i = 0; (chr = phone[i]) != '\0'; i++) {
        if (check_char(chr, "+.-( )")) {
           continue;
        }

       if (!isdigit(chr) || len >= MAX_LEN) {
            return error(result);
        }

        len += sprintf(result + len, "%c", chr);
    }

    if (len == MAX_LEN) {
        // check country code
        if (!check_char(result[0], "1")) {
            return error(result);
        }

        len = sprintf(result, "%s", result + 1);
    }

    if (len != PHONE_LEN) {
        return error(result);
    }

    // check area code and exchange code
    if (!check_char(result[0], "23456789")
     || !check_char(result[3], "23456789")) {
        return error(result);
    }

    return result;
}
