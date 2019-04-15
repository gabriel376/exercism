#include "series.h"
#include <stdlib.h>
#include <string.h>

series_results_t series(const char *text, int series_len) {
    int text_len = strlen(text);

    series_results_t results;
    results.substring_count = 0;
    results.substring = NULL;

    if (!text || series_len <= 0 || series_len > text_len) {
        return results;
    }

    int count = text_len - series_len + 1;

    results.substring_count = count;
    results.substring = calloc(count, sizeof(char*));

    for (int i = 0; i < count; i++) {
        results.substring[i] = calloc(series_len+1, sizeof(char));
        strncpy(results.substring[i], text+i, series_len);
    }

    return results;
}
