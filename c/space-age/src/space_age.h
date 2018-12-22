#ifndef SPACE_AGE_H
#define SPACE_AGE_H

#define EARTH   (365.25 * 24 * 60 * 60)
#define MERCURY EARTH * 0.2408467
#define VENUS   EARTH * 0.61519726
#define MARS    EARTH * 1.8808158
#define JUPITER EARTH * 11.862615
#define SATURN  EARTH * 29.447498
#define URANUS  EARTH * 84.016846
#define NEPTUNE EARTH * 164.79132

double convert_planet_age(double period, long seconds);

#endif
