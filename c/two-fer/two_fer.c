#include "two_fer.h"
#include <stdio.h>

void two_fer(char * const response,
             const char * const name) {
  sprintf(response,
          "One for %s, one for me.",
          name == NULL ? "you" : name);
}
