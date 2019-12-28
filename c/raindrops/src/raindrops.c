#include <stdio.h>
#include "raindrops.h"

void convert(char *buffer, int num) {
    size_t len = sprintf(buffer, "%s%s%s",
        num % 3 == 0 ? "Pling" : "",
        num % 5 == 0 ? "Plang" : "",
        num % 7 == 0 ? "Plong" : "");
    if (len <= 0)
        sprintf(buffer, "%d", num);
}
