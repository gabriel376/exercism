#include "isogram.h"

#include <string.h>
#include <ctype.h>

bool is_isogram(const char phrase[]) {
    if (phrase == NULL)
        return false;

    bool letters[26] = { false };
    size_t idx = 0;

    for (int i = 0; phrase[i] != '\0'; i++) {
        if (!isalpha(phrase[i]))
            continue;

        idx = toupper(phrase[i]) - 'A';

        if (letters[idx])
            return false;

        letters[idx] = true;
    }

    return true;
}
