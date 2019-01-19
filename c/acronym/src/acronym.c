#include <stdlib.h>
#include <ctype.h>

char *abbreviate(const char * const input) {
  if (input == NULL || input[0] == '\0') {
    return NULL;
  }

  char *acronym = NULL;
  int len = 0;

  for (int i = 0; input[i] != '\0'; i++) {
    if (i == 0 || input[i-1] == ' ' || input[i-1] == '-') {
      len++;
      acronym = realloc(acronym, len + 1);
      acronym[len-1] = toupper(input[i]);
      acronym[len] = '\0';
    }
  }

  return acronym;
}
