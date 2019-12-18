#ifndef PYTHAGOREAN_TRIPLET
#define PYTHAGOREAN_TRIPLET

#include <stdint.h>
#include <stddef.h>

typedef uint16_t triplet_side_t;

typedef struct {
    triplet_side_t a;
    triplet_side_t b;
    triplet_side_t c;
} triplet_t;

typedef struct {
    size_t count;
    triplet_t triplets[];
} triplets_t;

triplets_t* triplets_with_sum(triplet_side_t sum);

void free_triplets(triplets_t *triplets);

#endif
