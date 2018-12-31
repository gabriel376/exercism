#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "pig_latin.h"

bool is_vowel(char letter) {
  switch (letter) {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
    return true;
  }
  return false;
}

bool is_vowel_sound(const char *text) {
  char first = text[0];
  char second = text[1];
  return is_vowel(first) ||
    ((first == 'x' || first == 'y') && !is_vowel(second));
}

int first_vowel_index(const char *text) {
  for (int i = 1; text[i] != '\0'; i++) {
    if (text[i] == 'y' ||
        (is_vowel(text[i]) &&  (text[i - 1] != 'q' || text[i] != 'u'))) {
      return i;
    }
  }
  return -1;
}

char* translate(const char* text) {
  int text_len = strlen(text);

  char *result = malloc(3 * text_len * sizeof(char));
  strcpy(result, "");

  char buffer[text_len];
  int buffer_len = 0;

  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] != ' ') {
      buffer[buffer_len] = text[i];
      buffer_len++;
      buffer[buffer_len] = '\0';
    }

    if (text[i] == ' ' || text[i + 1] == '\0') {
      if (is_vowel_sound(buffer)) {
        strcat(buffer, "ay");
        buffer_len += 2;

      } else {
        int index = first_vowel_index(buffer);
        char temp[buffer_len];
        strcpy(temp, buffer);
        for (int j = index; j < buffer_len; j++) {
          buffer[j - index] = temp[j];
        }
        for (int j = 0; j < index; j++) {
          buffer[buffer_len - index + j] = temp[j];
        }
        strcat(buffer, "ay");
      }

      strcat(result, buffer);
      if (text[i] == ' ') {
        strcat(result, " ");
      }
      strcpy(buffer, "");
      buffer_len = 0;
    }
  }

  return result;
}
