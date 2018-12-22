#include <stddef.h>
#include "hamming.h"

int compute(const char* const left, const char* const right) {
  int const error = -1;
  
  if (left == NULL || right == NULL) {
    return error;
  }

  int distance = 0;
  int index = 0;
  for (index = 0; left[index] != '\0' && right[index] != '\0'; index++) {
    if (left[index] != right[index]) {
      distance++;
    }
  }

  if (left[index] != '\0' || right[index] != '\0') {
    return error;
  }
  
  return distance;
}
