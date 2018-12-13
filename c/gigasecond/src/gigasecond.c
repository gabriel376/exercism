#include <time.h>
#include "gigasecond.h"

#define GIGA 1e9

time_t gigasecond_after(time_t time) {
  return time + GIGA;
}
