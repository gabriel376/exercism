#include "clock.h"

#include <stdio.h>
#include <string.h>

#define MINUTES_IN_DAY  24 * 60
#define CLOCK_FORMAT    "%02d:%02d"

static int clock_minutes(int hour, int minute) {
    int minutes = hour*60 + minute;
    minutes %= MINUTES_IN_DAY;
    minutes += MINUTES_IN_DAY;
    minutes %= MINUTES_IN_DAY;
    return minutes;
}

clock_t clock_create(int hour, int minute) {
    int minutes = clock_minutes(hour, minute);
    clock_t clock;
    snprintf(clock.text, MAX_STR_LEN, CLOCK_FORMAT, minutes/60, minutes%60);
    return clock;
}

clock_t clock_add(clock_t clock, int minutes) {
    int hour, minute;
    sscanf(clock.text, CLOCK_FORMAT, &hour, &minute);
    return clock_create(0, clock_minutes(hour, minute) + minutes);
}

clock_t clock_subtract(clock_t clock, int minutes) {
    return clock_add(clock, -minutes);
}

bool clock_is_equal(clock_t a, clock_t b) {
    return !strcmp(a.text, b.text);
}
