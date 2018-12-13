#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_LEN 254

char *abbreviate(const char *phrase) {
  if (phrase == NULL || phrase[0] == '\0') {
    return NULL;
  }

  char *acronym = NULL;
  int len = 0;
  int add = 1;

  for (int i = 0; phrase[i] != '\0'; i++) {
    if (add) {
      if (len % BUFFER_LEN == 0) {
        int buffer_size = BUFFER_LEN * ((len / BUFFER_LEN) + 1);
        acronym = realloc(acronym, (buffer_size + 2) * sizeof(char));
        if (acronym == NULL) {
          free(acronym);
          printf("Error allocating memory.\n");
          exit(EXIT_FAILURE);
        }
      }
      acronym[len] = toupper(phrase[i]);
      acronym[len + 1] = '\0';  
      len++;
      add = 0;
    }

    if (phrase[i] == ' ' || phrase[i] == '-') {
      add = 1;
    }
  }

  return acronym;
}
