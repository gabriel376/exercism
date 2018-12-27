#include "grains.h"

unsigned long long square(int n) {
  if (n < MIN || n > MAX) {
    return 0;
  }
  return 1ull << (n - 1);
}

unsigned long long total() {
    return (2ull << (MAX - 1)) - 1;
}
