#include "square_root.h"

int squareRoot(int radicand) {
    int root = 1;
    int last = 0;

    while (root != last) {
        last = root;
        root = (root + radicand/root) / 2;
    }

    if (root*root > radicand) {
        return root - 1;
    }

    return root;
}
