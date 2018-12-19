#include <stddef.h>
#include "hamming.h"

int compute(const char* const left, const char* const right) {
  int const error = -1;
  int distance = 0;
  int index = 0;

  if (left == NULL || right == NULL) {
    return error;
  }

  for (index = 0; left[index] != '\0'; index++) {
    if (left[index] != right[index]) {
      distance++;
    }
  }

  if (right[index] == '\0') {
    return distance;
  } else {
    return error;
  }
}
