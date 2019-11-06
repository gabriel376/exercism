#include "crypto_square.h"

#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

char *ciphertext(const char *input) {
  char *chars = malloc((strlen(input) + 1) * sizeof(char));
  int len = 0;
  
  for (int i = 0; input[i] != '\0'; i++) {
    if (isalnum(input[i])) {
      chars[len++] = tolower(input[i]);
    }
  }
  chars[len] = '\0';

  int nrows = ceil(sqrt(len));
  int ncols = nrows == 0 ? 0 : (len + nrows - 1) / nrows;
  int index = 0;
  char *crypto = malloc(((nrows + 1) * ncols + 1) * sizeof(char));

  for (int i = 0; i < nrows; i++) {
    for (int j = 0; j < ncols; j++) {
      int c = j*nrows + i;
      if (c < len) {
	crypto[index++] = chars[c];
      } else {
	crypto[index++] = ' ';
      }
    }
    if (i < nrows - 1) {
      crypto[index++] = ' ';
    }
  }
  crypto[index] = '\0';

  free(chars);
  
  return crypto;
}
