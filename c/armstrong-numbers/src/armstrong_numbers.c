#include "armstrong_numbers.h"

static int power(int base, int exp) {
    int result = 1;

    for (int i = 0; i < exp; i++) {
        result *= base;
    }

    return result;
}

bool isArmstrongNumber(int input) {
    int digits[32];
    int len = 0;
    int total = 0;

    for (int num = input; num > 0; num /= 10) {
        digits[len++] = num % 10;
    }

    for (int i = 0; i < len; i++) {
        total += power(digits[i], len);
    }

    return total == input;
}
