#include "saddle_points.h"

#include <stdbool.h>

static bool isSaddlePoint(size_t nrows,
                          size_t ncols,
                          size_t row,
                          size_t col,
                          uint8_t matrix[nrows][ncols]) {

    for (size_t i = 0; i < nrows; i++) {
        if (matrix[row][col] > matrix[i][col]) {
            return false;
        }
    }

    for (size_t i = 0; i < ncols; i++) {
        if (matrix[row][col] < matrix[row][i]) {
            return false;
        }
    }

    return true;
}

saddle_points_t* saddlePoints(size_t nrows,
                              size_t ncols,
                              uint8_t matrix[nrows][ncols]) {

    saddle_points_t *saddle = calloc(1, sizeof(saddle_points_t));
    saddle->points = calloc(nrows * ncols, sizeof(saddle_point_t));

    for (size_t i = 0; i < nrows; i++) {
        for (size_t j = 0; j < ncols; j++) {
            if (isSaddlePoint(nrows, ncols, i, j, matrix)) {
                saddle->points[saddle->count].row = i + 1;
                saddle->points[saddle->count].column = j + 1;
                saddle->count++;
            }
        }
    }

    return saddle;
}
