#include <stddef.h>
#include "hamming.h"

int compute(char *a, char *b) {
  int error = -1;
  int diff = 0;
  int i = 0;
  
  if (a == NULL || b == NULL) {
    return error;
  }

  while (1) {
    if (a[i] == '\0' && b[i] == '\0')
      return diff;

    if (a[i] == '\0' || b[i] == '\0')
      return error;

    if (a[i] != b[i])
      diff++;

    i++;
  }
}
