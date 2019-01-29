#include "binary_search.h"

int* binary_search(const int num, const int * const array, const int len) {
  int min = 0;
  int max = len - 1;

  while (min <= max) {
    int mid = (min + max) / 2;

    if (array[mid] == num) {
      return (int*) &array[mid];
    }

    if (num < array[mid]) {
      max = mid - 1;
    } else {
      min = mid + 1;
    }
  }

  return 0;
}
