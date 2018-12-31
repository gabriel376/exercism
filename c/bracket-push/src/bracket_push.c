#include <stdbool.h>
#include <string.h>
#include "bracket_push.h"

#define DELIMITERS_LEN 3
char DELIMITERS[DELIMITERS_LEN][2] = {
  { '[', ']' },
  { '{', '}' },
  { '(', ')' },
};

bool is_delimiter(char symbol, int type) {
  for (int i = 0; i < DELIMITERS_LEN; i++) {
    if (symbol == DELIMITERS[i][type]) {
      return true;
    }
  }
  return false;
}

bool is_delimiter_open(char symbol) {
  return is_delimiter(symbol, 0);
}

bool is_delimiter_close(char symbol) {
  return is_delimiter(symbol, 1);
}

bool is_match(char open, char close) {
  for (int i = 0; i < DELIMITERS_LEN; i++) {
    if (open == DELIMITERS[i][0] && close == DELIMITERS[i][1]) {
      return true;
    }
  }
  return false;
}

bool is_paired(const char *input) {
  char buffer[strlen(input) + 1];
  int len = 0;

  for (int i = 0; input[i] != '\0'; i++) {
    if (is_delimiter_open(input[i])) {
      len++;
      buffer[len - 1] = input[i];

    } else if (is_delimiter_close(input[i]) && len > 0) {
      if (is_match(buffer[len - 1], input[i])) {
        buffer[len - 1] = '\0';
        len--;

      } else {
        return false;
      }
    }
  }

  return len == 0;
}
