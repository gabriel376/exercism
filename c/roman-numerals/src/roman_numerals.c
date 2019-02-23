#include "roman_numerals.h"
#include <stdlib.h>
#include <string.h>

typedef struct {
    int value;
    const char *symbol;
} Numeral;

static const Numeral NUMERALS[] = {
  { 1000, "M"  },
  {  900, "CM" },
  {  500, "D"  },
  {  400, "CD" },
  {  100, "C"  },
  {   90, "XC" },
  {   50, "L"  },
  {   40, "XL" },
  {   10, "X"  },
  {    9, "IX" },
  {    5, "V"  },
  {    4, "IV" },
  {    1, "I"  },
};

char* to_roman_numeral(int number) {
  char *symbols = calloc(32, sizeof(char));

  int index = 0;
  while (number > 0) {
    const Numeral *numeral = &NUMERALS[index];

    if (number < numeral->value) {
      index++;
      continue;
    }

    number -= numeral->value;
    strncat(symbols, numeral->symbol, 2);
  }

  return symbols;
}
