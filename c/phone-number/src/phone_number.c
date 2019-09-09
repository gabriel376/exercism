#include "phone_number.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ERROR       "0000000000"
#define PHONE_LEN   10
#define MAX_LEN     PHONE_LEN + 1

static char* error(char *data) {
    sprintf(data, "%s", ERROR);
    return data;
}

char* phone_number_clean(const char *phone) {
    char *result = calloc(MAX_LEN + 1, sizeof(char));
    char chr;
    int len = 0;

    for (int i = 0; (chr = phone[i]) != '\0'; i++) {
        // ignore these characters
        if (strchr("+.-( )", chr)) {
           continue;
        }

        // error if not a digit or exceed maximum length
        if (!isdigit(chr) || len >= MAX_LEN) {
            return error(result);
        }

        // append char to final string
        len += sprintf(result + len, "%c", chr);
    }

    if (len == MAX_LEN) {
        // check country code
        if (!strchr("1", result[0])) {
            return error(result);
        }

        // remove country code
        len = sprintf(result, "%s", result + 1);
    }

    if (len != PHONE_LEN) {
        return error(result);
    }

    // check area code and exchange code
    if (!strchr("23456789", result[0])
     || !strchr("23456789", result[3])) {
        return error(result);
    }

    return result;
}
