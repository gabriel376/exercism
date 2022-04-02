#include "space_age.h"

float age(planet_t planet,
          int64_t seconds) {
  switch (planet) {
  case EARTH:   return seconds / (365.25 * 24 * 60 * 60);
  case MERCURY: return age(EARTH, seconds) / 0.2408467;
  case VENUS:   return age(EARTH, seconds) / 0.6151973;
  case MARS:    return age(EARTH, seconds) / 1.8808158;
  case JUPITER: return age(EARTH, seconds) / 11.862615;
  case SATURN:  return age(EARTH, seconds) / 29.447498;
  case URANUS:  return age(EARTH, seconds) / 84.016846;
  case NEPTUNE: return age(EARTH, seconds) / 164.79132;
  }

  return -1;
}
