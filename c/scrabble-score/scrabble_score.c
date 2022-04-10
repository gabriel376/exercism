#include "scrabble_score.h"

#include <ctype.h>

unsigned int score(const char * const word) {
  int result = 0;

  for (int i = 0; word[i] != '\0'; i++) {
    switch (toupper(word[i])) {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'L':
    case 'N':
    case 'R':
    case 'S':
    case 'T':
      result += 1;
      break;

    case 'D':
    case 'G':
      result += 2;
      break;

    case 'B':
    case 'C':
    case 'M':
    case 'P':
      result += 3;
      break;

    case 'F':
    case 'H':
    case 'V':
    case 'W':
    case 'Y':
      result += 4;
      break;

    case 'K':
      result += 5;
      break;

    case 'J':
    case 'X':
      result += 8;
      break;

    case 'Q':
    case 'Z':
      result += 10;
      break;
    }
  }

  return result;
}
