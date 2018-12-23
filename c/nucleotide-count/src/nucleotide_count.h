#include <stdbool.h>

#ifndef NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H

typedef struct {
  char symbol;
  int count;
} Nucleotide;

Nucleotide* Nucleotide_new(const char symbol);
Nucleotide** Nucleotides_new(const char *symbols);
int Nucleotides_find(const char symbol, const int len, Nucleotide **nucleotides);
bool Nucleotides_count(const char *strand, const int len, Nucleotide **nucleotides);
char* Nucleotides_summarize(const int len, Nucleotide **nucleotides);
void Nucleotides_destroy(const int len, Nucleotide **nucleotides);
char* count(const char *strand);

#endif
