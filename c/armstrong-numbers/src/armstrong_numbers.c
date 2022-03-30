#include "armstrong_numbers.h"
#include <stdio.h>
#include <math.h>

bool isArmstrongNumber(const int number) {
  char buffer[32];
  int sum = 0;
  int length = sprintf(buffer, "%d", number);

  for (int i = 0; i < length; i++) {
    sum += pow(buffer[i] - '0', length);
  }

  return number == sum;
}
