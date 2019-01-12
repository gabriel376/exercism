#include "difference_of_squares.h"

unsigned long square_of_sum(const unsigned long n) {
  unsigned long sum = 0;
  for (unsigned long i = 1; i <= n; i++) {
    sum += i;
  }
  return sum * sum;
}

unsigned long sum_of_squares(const unsigned long n) {
  unsigned long sum = 0;
  for (unsigned long i = 1; i <= n; i++) {
    sum += i * i;
  }
  return sum;
}

unsigned long difference_of_squares(const unsigned long n) {
  return square_of_sum(n) - sum_of_squares(n);
}
