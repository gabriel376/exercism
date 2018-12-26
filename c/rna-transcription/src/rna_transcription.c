#include "rna_transcription.h"
#include <stdlib.h>
#include <string.h>

const char SYMBOLS[5][2] = {
  {'A', 'U'},
  {'C', 'G'},
  {'G', 'C'},
  {'T', 'A'},
  {'\0', '\0'},
};

char transcript(const char * const symbol) {
  for (int i = 0; SYMBOLS[i][0] != '\0'; i++) {
    if (*symbol == SYMBOLS[i][0]) {
      return SYMBOLS[i][1];
    }
  }
  return '\0';
}

char* to_rna(const char * const dna) {
  int len = strlen(dna) + 1;
  char *rna = malloc(len * sizeof(char));
  for (int i = 0; dna[i] != '\0'; i++) {
    char symbol = transcript(&dna[i]);
    if (symbol == '\0') {
      free(rna);
      return NULL;
    }
    rna[i] = symbol;
  }
  rna[len-1] = '\0';
  return rna;
}
