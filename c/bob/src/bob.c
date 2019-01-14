#include <stdbool.h>
#include <ctype.h>
#include "bob.h"

const char* hey_bob(const char *text) {
  bool question = false;
  bool upper = true;
  bool silence = true;
  bool alpha = false;

  for (int i = 0; text[i] != '\0'; i++) {
    if (question && isalnum(text[i]))
      question = false;

    if (text[i] == '?')
      question = true;

    if (text[i] != toupper(text[i]))
      upper = false;

    if (isalpha(text[i]))
      alpha = true;

    if (!isspace(text[i]))
      silence = false;
  }

  if (alpha && upper && question)
    return "Calm down, I know what I'm doing!";

  if (alpha && upper)
    return "Whoa, chill out!";

  if (question)
    return "Sure.";

  if (silence)
    return "Fine. Be that way!";

  return "Whatever.";
}
