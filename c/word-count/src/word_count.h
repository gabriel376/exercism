#ifndef WORD_COUNT_H
#define WORD_COUNT_H

#define MAX_WORDS 20
#define MAX_WORD_LENGTH 50

#define EXCESSIVE_LENGTH_WORD -1
#define EXCESSIVE_NUMBER_OF_WORDS -2

typedef struct word_count_word {
   char text[MAX_WORD_LENGTH + 1];
   int count;
} word_count_word_t;

int word_count(const char *input_text, word_count_word_t *words);

#endif
