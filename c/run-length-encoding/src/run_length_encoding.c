#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "run_length_encoding.h"

#define BUFFER_LEN 138

char* encode(const char* data) {
    char* result = calloc(BUFFER_LEN, sizeof(char));

    int i = 0;
    int count = 0;
    int offset = 0;
    char element = '\0';

    do {
        if (data[i] == element) {
            count++;
            continue;
        }

        if (count) {
            offset += sprintf(result + offset, "%d", count + 1);
        }

        if (element) {
            offset += sprintf(result + offset, "%c", element);
        }

        element = data[i];
        count = 0;

    } while (data[i++] != '\0');

    return result;
}

char* decode(const char* data) {
    char* result = calloc(BUFFER_LEN, sizeof(char));

    int i = 0;
    int len = 0;
    int count = 0;

    do {
        if (isdigit(data[i])) {
            count *= 10;
            count += data[i] - '0';
            continue;
        }

        if (count == 0) {
            count = 1;
        }

        while (count--) {
            result[len++] = data[i];
        }

        count = 0;

    } while(data[i++] != '\0');

    result[len] = '\0';

    return result;
}
