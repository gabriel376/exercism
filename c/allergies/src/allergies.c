#include "allergies.h"
#include <stdlib.h>

bool is_allergic_to(allergen_t allergen, int score) {
    return score & (1 << allergen);
}

void get_allergens(int score, allergen_list_t *list) {
    list->count = 0;
    list->allergens = malloc(ALLERGEN_COUNT * sizeof(allergen_t));
    for (allergen_t allergen = 0; allergen < ALLERGEN_COUNT; allergen++) {
        if (is_allergic_to(allergen, score)) {
	    list->allergens[list->count++] = allergen;
	}
    }
}

