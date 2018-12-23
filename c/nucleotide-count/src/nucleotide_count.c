#include "nucleotide_count.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

Nucleotide* Nucleotide_new(const char symbol) {
  Nucleotide *nucleotide = malloc(1 * sizeof(Nucleotide));
  nucleotide->symbol = symbol;
  nucleotide->count = 0;
  return nucleotide;
}

Nucleotide** Nucleotides_new(const char *symbols) {
  int len = strlen(symbols);
  Nucleotide **nucleotides = malloc(len * sizeof(Nucleotide*));
  for (int i = 0; i < len; i++) {
    Nucleotide *nucleotide = Nucleotide_new(symbols[i]);
    nucleotides[i] = nucleotide;
  }
  return nucleotides;
}

int Nucleotides_find(const char symbol, const int len, Nucleotide **nucleotides) {
  for (int i = 0; i < len; i++) {
    if (nucleotides[i]->symbol == symbol) {
      return i;
    }
  }
  return -1;
}

bool Nucleotides_count(const char *strand, const int len, Nucleotide **nucleotides) {
  for (int i = 0; strand[i] != '\0'; i++) {
    int index = Nucleotides_find(strand[i], len, nucleotides);
    if (index < 0) {
      return false;
    }
    nucleotides[index]->count++;
  }
  return true;
}

char* Nucleotides_summarize(const int len, Nucleotide **nucleotides) {
  char *summary = calloc(5 * len, sizeof(char));
  for (int i = 0; i < len; i++) {
    char buffer[4];
    sprintf(buffer, "%c:%d", nucleotides[i]->symbol, nucleotides[i]->count);
    if (i == 0) {
      sprintf(summary, "%s", buffer);
    } else {
      sprintf(summary, "%s %s", summary, buffer);
    }
  }
  return summary;
}

void Nucleotides_destroy(const int len, Nucleotide **nucleotides) {
  for (int i = 0; i < len; i++) {
    free(nucleotides[i]);
  }
  free(nucleotides);
}

char* count(const char *strand) {
  const char *symbols = "ACGT";
  const int len = 4;
  Nucleotide **nucleotides = Nucleotides_new(symbols);
  bool status = Nucleotides_count(strand, len, nucleotides);
  if (status == false) {
    Nucleotides_destroy(len, nucleotides);
    char *empty = calloc(1, sizeof(char));
    return empty;
  }
  char *summary = Nucleotides_summarize(len, nucleotides);
  Nucleotides_destroy(len, nucleotides);
  return summary;
}
