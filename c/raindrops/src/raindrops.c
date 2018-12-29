#include <stdio.h>
#include <stdbool.h>
#include "raindrops.h"

typedef struct {
  char *text;
  int value;
} Drop;

#define DROPS_LEN 3
const Drop DROPS[DROPS_LEN] = {
    { .value = 3, .text = "Pling" },
    { .value = 5, .text = "Plang" },
    { .value = 7, .text = "Plong" },
};

void convert(char *buffer, int value) {
  bool found = false;

  for (int i = 0; i < DROPS_LEN; i++) {
    if (value % DROPS[i].value == 0) {
      buffer += sprintf(buffer, "%s", DROPS[i].text);
      found = true;
    }
  }

  if (!found) {
    sprintf(buffer, "%d", value);
  }
}
