#include "darts.h"

#include <math.h>

#define INNER_RADIUS  1.0F
#define MIDDLE_RADIUS 5.0F
#define OUTER_RADIUS  10.0F

#define INNER_SCORE  10
#define MIDDLE_SCORE 5
#define OUTER_SCORE  1

int score(coordinate_t coord) {
    float position = sqrt(pow(coord.x, 2) + pow(coord.y, 2));

    if (position <= INNER_RADIUS)  return INNER_SCORE;
    if (position <= MIDDLE_RADIUS) return MIDDLE_SCORE;
    if (position <= OUTER_RADIUS)  return OUTER_SCORE;

    return 0;
}
