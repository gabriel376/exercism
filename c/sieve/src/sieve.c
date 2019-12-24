#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
  uint32_t numbers[limit+1];
  size_t count = 0;

  for (uint32_t i = 0; i <= limit; i++) {
    numbers[i] = 0;
  }

  for (uint32_t i = 2; i <= limit; i++) {
    if (numbers[i] == 0) {
      primes[count++] = i;
    }

    if (count >= max_primes) {
      break;
    }

    for (uint32_t j = i+i; j <= limit; j += i) {
      numbers[j] = 1;
    }
  }

  return count;
}
