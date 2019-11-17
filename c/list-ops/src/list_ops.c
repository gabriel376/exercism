#include "list_ops.h"

#include <stdlib.h>
#include <string.h>

#include <stdio.h>

list_t* new_list(size_t length,
                list_value_t values[]) {
    list_t *list = malloc(sizeof(list_t) + length * sizeof(list_value_t));

    list->length = length;
    memcpy(list->values, values, length * sizeof(list_value_t));

    return list;
}

list_t* append_list(list_t *list1,
                    list_t *list2) {
    size_t length = list1->length + list2->length;
    list_value_t values[length];

    memcpy(values, list1->values, list1->length * sizeof(list_value_t));
    memcpy(values + list1->length, list2->values, list2->length * sizeof(list_value_t));

    return new_list(length, values);
}

list_t* filter_list(list_t *list,
                    bool(*filter) (list_value_t value)) {
    size_t length = 0;
    list_value_t values[list->length];

    for (size_t i = 0; i < list->length; i++) {
        if (filter(list->values[i])) {
            values[length++] = list->values[i];
        }
    }

    return new_list(length, values);
}

size_t length_list(list_t *list) {
    return list->length;
}

list_t* map_list(list_t *list,
                 list_value_t(*map) (list_value_t value)) {
    size_t length = list->length;
    list_value_t values[list->length];

    for (size_t i = 0; i < list->length; i++) {
        values[i] = map(list->values[i]);
    }

    return new_list(length, values);
}

list_value_t foldl_list(list_t *list,
                        list_value_t initial,
                        list_value_t(*foldl) (list_value_t value,
                                              list_value_t initial)) {
    list_value_t total = initial;

    for (size_t i = 0; i < list->length; i++) {
        total = foldl(list->values[i], total);
    }

    return total;
}

list_value_t foldr_list(list_t *list,
                        list_value_t initial,
                        list_value_t(*foldr) (list_value_t value,
                                              list_value_t initial)) {
    list_value_t total = initial;

    for (size_t i = 0; i < list->length; i++) {
        total = foldr(list->values[list->length - 1 - i], total);
    }

    return total;
}

list_t* reverse_list(list_t *list) {
    for (size_t i = 0; i < list->length / 2; i++) {
        list_value_t temp = list->values[i];
        list->values[i] = list->values[list->length - i - 1];
        list->values[list->length - i - 1] = temp;
    }

    return list;
}

void delete_list(list_t *list) {
    free(list);
}
