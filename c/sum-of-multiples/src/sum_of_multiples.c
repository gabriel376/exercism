#include <stdlib.h>
#include "sum_of_multiples.h"

unsigned int sum_of_multiples(const unsigned int * const multiples,
                              const unsigned int len,
                              const unsigned int num) {
  unsigned int sum = 0;

  if (multiples == NULL) {
    return sum;
  }

  for (unsigned int i = 1; i < num; i++) {
    for (unsigned int j = 0; j < len; j++) {
      if (multiples[j] > 0 && i % multiples[j] == 0) {
        sum += i;
        break;
      }
    }
  }

  return sum;
}
