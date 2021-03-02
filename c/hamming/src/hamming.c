#include "hamming.h"

int compute(const char* lhs, const char* rhs) {
  if (!lhs || !rhs)
    return -1;

  int result = 0;
  for (; *lhs && *rhs; lhs++, rhs++)
    if (*lhs != *rhs)
      result++;

  if (*lhs != '\0' || *rhs != '\0')
    return -1;

  return result;
}
