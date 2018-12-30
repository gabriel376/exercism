#include <stdbool.h>
#include <string.h>
#include "meetup.h"

#define ONE_WEEK    7
#define TWO_WEEKS   2 * ONE_WEEK
#define THREE_WEEKS 3 * ONE_WEEK
#define FOUR_WEEKS  4 * ONE_WEEK

bool is_leap(int year) {
  return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int days_in_month(int year, int month) {
  int DAYS_IN_MONTH[12] = {
    /* Jan */ 31,
    /* Feb */ is_leap(year) ? 29 : 28,
    /* Mar */ 31,
    /* Apr */ 30,
    /* May */ 31,
    /* Jun */ 30,
    /* Jul */ 31,
    /* Aug */ 31,
    /* Sep */ 30,
    /* Oct */ 31,
    /* Nov */ 30,
    /* Dec */ 31,
  };

  return DAYS_IN_MONTH[month - 1];
}

int days_in_year(int year) {
  return is_leap(year) ? 366 : 365;
}

int get_weekday_num(const char *weekday_name) {
  char *WEEKDAYS[ONE_WEEK] = {
    /* 0 */ "Sunday",
    /* 1 */ "Monday",
    /* 2 */ "Tuesday",
    /* 3 */ "Wednesday",
    /* 4 */ "Thursday",
    /* 5 */ "Friday",
    /* 6 */ "Saturday",
  };

  for (int i = 0; i < ONE_WEEK; i++) {
    if (strcmp(WEEKDAYS[i], weekday_name) == 0) {
      return i;
    }
  }

  return -1;
}

int first_weekday_in_month(int year, int month) {
  int base_year = 1970;
  int base_month = 1;
  int base_weekday = get_weekday_num("Thursday");

  int diff = 0;
  for (int i = base_year; i < year; i++) {
    diff += days_in_year(i);
  }
  for (int i = base_month; i < month; i++) {
    diff += days_in_month(year, i);
  }

  return (diff + base_weekday) % ONE_WEEK;
}

int meetup_day_of_month(int year, int month, const char *descriptor, const char *weekday_name) {
  int start_weekday = first_weekday_in_month(year, month);
  int day = get_weekday_num(weekday_name) - start_weekday + 1;

  if (day <= 0) {
    day += ONE_WEEK;
  }

  if (strcmp(descriptor, "second") == 0) {
    day += ONE_WEEK;

  } else if (strcmp(descriptor, "third") == 0) {
    day += TWO_WEEKS;

  } else if (strcmp(descriptor, "teenth") == 0) {
    day += TWO_WEEKS;

    if (day + 1 < TWO_WEEKS) {
      day += ONE_WEEK;

    } else if (day + 2 > THREE_WEEKS) {
      day -= ONE_WEEK;
    }

  } else if (strcmp(descriptor, "fourth") == 0) {
    day += THREE_WEEKS;

  } else if (strcmp(descriptor, "fifth") == 0) {
    day += FOUR_WEEKS;

    if (day > days_in_month(year, month)) {
      day = 0;
    }

  } else if (strcmp(descriptor, "last") == 0) {
    day += FOUR_WEEKS;

    if (day > days_in_month(year, month)) {
      day -= ONE_WEEK;
    }
  }

  return day;
}

