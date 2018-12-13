#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_LEN 254

void add_letter(char **acronym, const char *letter, int index) {
  static int len = 0;
  if (index == 0) {
    len = 0;
  }

  if (len % BUFFER_LEN == 0) {
    int buffer_size = BUFFER_LEN * ((len / BUFFER_LEN) + 1);
    *acronym = realloc(*acronym, (buffer_size + 2) * sizeof(char));
    if (acronym == NULL) {
      free(acronym);
      printf("Error allocating memory.\n");
      exit(EXIT_FAILURE);
    }
  }

  (*acronym)[len] = toupper(*letter);
  (*acronym)[len + 1] = '\0';
  len++;
}

char *abbreviate(const char *phrase) {
  if (phrase == NULL || phrase[0] == '\0') {
    return NULL;
  }

  char *acronym = NULL;
  int add = 1;

  for (int i = 0; phrase[i] != '\0'; i++) {
    if (add) {
      add_letter(&acronym, &phrase[i],  i);
      add = 0;
    }

    if (phrase[i] == ' ' || phrase[i] == '-') {
      add = 1;
    }
  }

  return acronym;
}
