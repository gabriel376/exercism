#include <stdlib.h>
#include "secret_handshake.h"

#define LEN(arr) sizeof(arr) / sizeof(arr[0])

static const char *COMMANDS[] = {
  "wink",
  "double blink",
  "close your eyes",
  "jump",
};

const char** commands(const int secret) {
  const int len = LEN(COMMANDS);
  const char **result = calloc(len + 1, sizeof(char*));
  const int rev = secret & (1 << len);
  int count = 0;

  for (int i = rev ? len - 1 : 0; rev ? i >= 0 : i < len; rev ? i-- : i++) {
    if (secret & (1 << i)) {
      result[count++] = COMMANDS[i];
    }
  }

  return result;
}
