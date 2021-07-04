#include "sum_of_multiples.h"

#include <stdlib.h>

unsigned int sum(const unsigned int * const multiples,
                 const unsigned int len,
                 const unsigned int num) {

  unsigned int result = 0;

  if (multiples == NULL) {
    return result;
  }

  for (unsigned int i = 1; i < num; i++) {
    for (unsigned int j = 0; j < len; j++) {
      if (multiples[j] > 0 && i % multiples[j] == 0) {
        result += i;
        break;
      }
    }
  }

  return result;
}
