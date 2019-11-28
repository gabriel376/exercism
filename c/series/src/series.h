#ifndef SERIES_H
#define SERIES_H

typedef struct {
  unsigned int substring_count;
  char **substring;
} series_results_t;

series_results_t series(const char *text, int series_len);

#endif
