#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "beer_song.h"

char* get_bottles(int index) {
  char *buffer = NULL;

  if (index < 0) {
    index = 99;
  }

  switch (index) {
  case 0:
    asprintf(&buffer, "no more bottles");
    break;
  case 1:
    asprintf(&buffer, "1 bottle");
    break;
  default:
    asprintf(&buffer, "%d bottles", index);
    break;
  }

  return buffer;
}

char* get_action(int index) {
  char *buffer= NULL;

  switch (index) {
  case 0:
    asprintf(&buffer, "Go to the store and buy some more");
    break;
  case 1:
    asprintf(&buffer, "Take it down and pass it around");
    break;
  default:
    asprintf(&buffer, "Take one down and pass it around");
    break;
  }

  return buffer;
}

void verse(char *buffer, int index) {
  char *current = get_bottles(index);
  char *repeat = get_bottles(index);
  char *action = get_action(index);
  char *next = get_bottles(index-1);

  current[0] = toupper(current[0]);
  sprintf(buffer,
          "%s of beer on the wall, %s of beer.\n%s, %s of beer on the wall.\n",
          current,
          repeat,
          action,
          next);

  free(current);
  free(repeat);
  free(action);
  free(next);
}

void sing(char *buffer, int start, int end) {
  for (int i = start; i >= end; i--) {
    verse(buffer, i);
    if (i > end) {
      strcat(buffer, "\n");
    }
    buffer += strlen(buffer);
  }
}
