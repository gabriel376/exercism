#include "grains.h"

unsigned long long square(int n) {
  return (n < MIN || n > MAX)
    ? 0
    : 1ull << (n - 1);
}

unsigned long long total() {
  unsigned long long grains = 0;
  for (int i = MIN; i <= MAX; i++) {
    grains += square(i);
  }
  return grains;
}
