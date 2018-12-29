#include <stdlib.h>
#include "secret_handshake.h"

#define LEN 4

const char *COMMANDS[LEN] = {
  "wink",
  "double blink",
  "close your eyes",
  "jump",
};

const char** commands(int secret) {
  const char **result = malloc(LEN * sizeof(char*));

  int count = 0;
  int rev = secret & (1 << LEN);
  for (int i = rev ? LEN - 1 : 0; rev ? i >= 0 : i < LEN; rev ? i-- : i++) {
      if (secret & (1 << i)) {
        result[count] = COMMANDS[i];
        count++;
      }
    }

  return result;
}
