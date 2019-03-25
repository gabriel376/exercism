#include <stdbool.h>
#include <string.h>
#include "bracket_push.h"

static const int DELIMITERS_LEN = 3;
static const char DELIMITERS[][2] = {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'},
};

bool is_paired(const char *input) {
    int stack[strlen(input)];
    int pos = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        for (int j = 0; j < DELIMITERS_LEN; j++) {
            if (input[i] == DELIMITERS[j][0]) {
                stack[pos++] = j;

            } else if (input[i] == DELIMITERS[j][1]) {
                if (pos == 0 || stack[--pos] != j) {
                    return false;
                }
            }
        }
    }

    return pos == 0;
}
