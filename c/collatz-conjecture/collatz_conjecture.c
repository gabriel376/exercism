#include "collatz_conjecture.h"

int steps(int n) {
  if (n <= 0) return ERROR_VALUE;

  int i = 0;
  while (n != 1) {
    n = n & 1 ? (3 * n) + 1 : n >> 1;
    i++;
  }

  return i;
}
