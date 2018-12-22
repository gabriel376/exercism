#include "grains.h"

unsigned long long square(int n) {
  return (n < MIN || n > MAX)
    ? 0
    : 1ull << (n - 1);
}

unsigned long long total() {
  int grains = 0;
  for (int i = 1; i < MAX; i++) {
    grains += square(i);
  }
  return grains;
}
