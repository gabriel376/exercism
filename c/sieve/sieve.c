#include "sieve.h"

#include <stdbool.h>
#include <stdlib.h>

uint32_t sieve(const uint32_t limit,
               uint32_t * const primes,
               const size_t max_primes) {

  bool *marked = calloc(limit + 1, sizeof(*marked));
  if (marked == NULL) {
    return 0;
  }

  uint32_t count = 0;

  for (uint32_t i = 2; i <= limit; i++) {
    if (marked[i] == false) {
      primes[count++] = i;
    }

    if (count >= max_primes) {
      break;
    }

    for (uint32_t j = 2*i; j <= limit; j += i) {
      marked[j] = true;
    }
  }

  free(marked);

  return count;
}
