#include "perfect_numbers.h"

kind classify_number(int number) {
  if (number <= 0) {
    return ERROR;
  }

  int aliquot_sum = 0;
  for (int i = 1; i < number; i++) {
    if (number % i == 0) {
      aliquot_sum += i;
    }
  }

  if (aliquot_sum > number) {
    return ABUNDANT_NUMBER;
  }

  if (aliquot_sum < number) {
    return DEFICIENT_NUMBER;
  }

  return PERFECT_NUMBER;
}
