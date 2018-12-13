#include <string.h>
#include <ctype.h>
#include "isogram.h"

#define A 65
#define Z 90

bool is_isogram(const char phrase[]) {
  if (phrase == NULL) {
    return false;
  }

  if(strlen(phrase) == 0) {
    return true;
  }

  bool letters[26] = { false };

  for (int i = 0; phrase[i] != '\0'; i++) {
    char c = toupper(phrase[i]);
    if (c >= A && c <= Z) {
      if (letters[c - A] == true) {
        return false;
      }
      letters[c - A] = true;
    }
  }
  
  return true;
}
