#include "sum_of_multiples.h"

unsigned int sum(const unsigned int * const factors,
                 const size_t nfactors,
                 const unsigned int limit) {
  unsigned int result = 0;

  if (factors == NULL) {
    return result;
  }

  for (unsigned int i = 1; i < limit; i++) {
    for (size_t j = 0; j < nfactors; j++) {
      if (factors[j] > 0 && i % factors[j] == 0) {
        result += i;
        break;
      }
    }
  }

  return result;
}
