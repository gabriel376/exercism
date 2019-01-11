#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "beer_song.h"

static char* get_bottles(const int index) {
  char *buffer = malloc(32);

  switch (index) {
  case 0:
    sprintf(buffer, "no more bottles");
    break;
  case 1:
    sprintf(buffer, "1 bottle");
    break;
  default:
    sprintf(buffer, "%d bottles", index < 0 ? 99 : index);
    break;
  }

  return buffer;
}

static char* get_action(const int index) {
  char *buffer= malloc(64);

  switch (index) {
  case 0:
    sprintf(buffer, "Go to the store and buy some more");
    break;
  case 1:
    sprintf(buffer, "Take it down and pass it around");
    break;
  default:
    sprintf(buffer, "Take one down and pass it around");
    break;
  }

  return buffer;
}

int verse(char * const buffer, const int index) {
  char *current = get_bottles(index);
  char *repeat = get_bottles(index);
  char *action = get_action(index);
  char *next = get_bottles(index-1);

  current[0] = toupper(current[0]);

  int len = sprintf(buffer,
          "%s of beer on the wall, %s of beer.\n%s, %s of beer on the wall.\n",
          current,
          repeat,
          action,
          next);

  free(current);
  free(repeat);
  free(action);
  free(next);

  return len;
}

int sing(char * const buffer, const int start, const int end) {
  int len = 0;

  for (int i = start; i >= end; i--) {
    len += verse(buffer+len, i);
    if (i > end) {
      len += sprintf(buffer+len, "\n");
    }
  }

  return len;
}
