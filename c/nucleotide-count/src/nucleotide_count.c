#include <stdio.h>
#include <stdlib.h>
#include "nucleotide_count.h"

typedef struct {
  char symbol;
  int count;
} Base;

int find(Base *bases, int len, char symbol) {
  for (int i = 0; i < len; i++) {
    if (bases[i].symbol == symbol) {
      return i;
    }
  }
  return -1;
}

char* count(const char *strand) {
  int len = 4;
  Base bases[] = {
    { .symbol = 'A', .count = 0, },
    { .symbol = 'C', .count = 0, },
    { .symbol = 'G', .count = 0, },
    { .symbol = 'T', .count = 0, },
  };

  char *summary = calloc(6 * len, sizeof(char));

  for (int i = 0; strand[i] != '\0'; i++) {
    int index = find(bases, len, strand[i]);
    if (index >= 0) {
      bases[index].count++;
    } else {
      return summary;
    }
  }

  int offset = 0;
  for (int i = 0; i < len; i++) {
    offset += sprintf(summary + offset, "%c:%d", bases[i].symbol, bases[i].count);
    if (i + 1 < len) {
      offset += sprintf(summary + offset, " ");
    }
  }

  return summary;
}
