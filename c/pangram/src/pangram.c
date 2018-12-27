#include <ctype.h>
#include "pangram.h"

#define NUM_LETTERS 26
#define ALL_LETTERS ((1 << NUM_LETTERS) - 1)

bool is_pangram(const char * const sentence) {
  if (!sentence) {
    return false;
  }

  int bitset = 0;
  for (int i = 0; sentence[i] != '\0'; i++) {
    char c = tolower(sentence[i]);
    if (isalpha(c)) {
      bitset |= 1 << (c - 'a');
    }
  }

  return bitset == ALL_LETTERS;
}
