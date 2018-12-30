#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "word_count.h"

void clear(char *buffer) {
  strcpy(buffer, "");
}

bool in_word(const char *text, int index) {
  char this = text[index];
  char previous = index == 0 ? '\0' : text[index - 1];
  char next = text[index + 1];
  return isalnum(this) || (isalpha(previous) && this == '\'' && isalpha(next));
}

void fill(char *buffer, char c) {
  int i = strlen(buffer);
  buffer[i] = c;
  buffer[i + 1] = '\0';
}

int find(char *text, word_count_word_t *words) {
  for (int i = 0; words[i].count > 0; i++) {
    if (strcmp(words[i].text, text) == 0) {
      return i;
    }
  }
  return -1;
}

int count(word_count_word_t *words) {
  int i = 0;
  while (words[i].count > 0) i++;
  return i;
}

void add(char *text, word_count_word_t *words) {
  int i = count(words);
  strcpy(words[i].text, text);
  words[i].count = 1;
}

int word_count(const char *text, word_count_word_t *words) {
  memset(words, 0, MAX_WORDS * sizeof(word_count_word_t));

  char buffer[MAX_WORD_LENGTH];
  clear(buffer);

  int i = 0;
  while (1) {
    if (strlen(buffer) > MAX_WORD_LENGTH) {
      return EXCESSIVE_LENGTH_WORD;
    }

    if (in_word(text, i)) {
      fill(buffer, tolower(text[i]));

    } else if (buffer[0] != '\0') {
      int index = find(buffer, words);
      if (index >= 0) {
        words[index].count++;

      } else if (count(words) >= MAX_WORDS) {
        return EXCESSIVE_NUMBER_OF_WORDS;

      } else {
        add(buffer, words);
      }

      clear(buffer);
    }

    if (text[i] == '\0') {
      break;
    }

    i++;
  }

  return count(words);
}
