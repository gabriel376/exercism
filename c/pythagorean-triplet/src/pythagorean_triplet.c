#include "pythagorean_triplet.h"

#include <stdlib.h>

triplets_t* triplets_with_sum(triplet_side_t sum) {
    triplets_t *triplets = malloc(sizeof(triplets_t));
    triplets->count = 0;

    triplet_side_t max = (sum - 3) / 3;
    for (triplet_side_t a = 1; a <= max; a++) {
        triplet_side_t b = ((sum - a) * (sum - a) - (a * a)) / (2 * (sum - a));
        triplet_side_t c = sum - a - b;
        if (a < b && a*a + b*b == c*c) {
            triplets->count++;
            triplets = realloc(triplets, sizeof(triplets_t) + triplets->count * sizeof(triplet_t));
            triplets->triplets[triplets->count - 1] = (triplet_t){a, b, c};
        }
    }

    return triplets;
}

void free_triplets(triplets_t *triplets) {
    free(triplets);
}
