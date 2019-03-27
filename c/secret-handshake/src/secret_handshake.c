#include <stdlib.h>
#include "secret_handshake.h"

static const char *COMMANDS[] = {
  "wink",
  "double blink",
  "close your eyes",
  "jump",
  NULL
};

static const int LEN = (sizeof(COMMANDS) / sizeof(char*)) - 1;

const char** commands(const int secret) {
  const char **result = malloc(LEN * sizeof(char*));
  const int rev = secret & (1 << LEN);
  int count = 0;

  for (int i = rev ? LEN - 1 : 0; rev ? i >= 0 : i < LEN; rev ? i-- : i++) {
      if (secret & (1 << i)) {
        result[count++] = COMMANDS[i];
      }
    }

  return result;
}
