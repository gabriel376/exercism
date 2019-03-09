#include "word_count.h"

#include <string.h>
#include <ctype.h>
#include <stdbool.h>

static bool in_word(const char * const text, const int index) {
    const char previous = index == 0 ? '\0' : text[index - 1];
    const char current = text[index];
    const char next = text[index + 1];
    return isalnum(current) ||
        (isalpha(previous) && current == '\'' && isalpha(next));
}

static int find(const char * const text, const word_count_word_t * const words) {
    for (int i = 0; words[i].count > 0; i++) {
        if (strcmp(words[i].text, text) == 0) {
            return i;
        }
    }
    return -1;
}

int word_count(const char * const text, word_count_word_t * const words) {
    char word[MAX_WORD_LENGTH];
    int len = 0;
    int count = 0;
    int i = 0;

    memset(words, 0, MAX_WORDS * sizeof(word_count_word_t));

    do {
        if (len > MAX_WORD_LENGTH) {
            return EXCESSIVE_LENGTH_WORD;
        }

        if (count >= MAX_WORDS) {
            return EXCESSIVE_NUMBER_OF_WORDS;
        }

        if (in_word(text, i)) {
            word[len++] = tolower(text[i]);
            word[len] = '\0';
            continue;
        }

        if (len == 0) {
            continue;
        }

        const int index = find(word, words);
        if (index >= 0) {
            words[index].count++;

        } else {
            strcpy(words[count].text, word);
            words[count++].count = 1;
        }

        strcpy(word, "");
        len = 0;

    } while (text[i++] != '\0');

    return count;
}
