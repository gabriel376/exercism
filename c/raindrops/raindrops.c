#include "raindrops.h"
#include <stdio.h>

void convert(char * const buffer,
             const int num) {
  size_t len = sprintf(buffer, "%s%s%s",
                       num % 3 == 0 ? "Pling" : "",
                       num % 5 == 0 ? "Plang" : "",
                       num % 7 == 0 ? "Plong" : "");

  if (len <= 0) {
    sprintf(buffer, "%d", num);
  }
}
