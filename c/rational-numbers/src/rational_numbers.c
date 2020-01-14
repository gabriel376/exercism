#include "rational_numbers.h"
#include <math.h>

/* a1/b1 + a2/b2 = (a1 * b2 + a2 * b1) / (b1 * b2) */
rational_t add(rational_t r1, rational_t r2) {
    return reduce((rational_t) {
        r1.numerator * r2.denominator + r2.numerator * r1.denominator,
        r1.denominator * r2.denominator,
    });
}

/* a1/b1 - a2/b2 = (a1 * b2 - a2 * b1) / (b1 * b2) */
rational_t subtract(rational_t r1, rational_t r2) {
    return reduce((rational_t) {
        r1.numerator * r2.denominator - r2.numerator * r1.denominator,
        r1.denominator * r2.denominator,
    });
}

/* a1/b1 * a2/b2 = (a1 * a2) / (b1 * b2) */
rational_t multiply(rational_t r1, rational_t r2) {
    return reduce((rational_t) {
        r1.numerator * r2.numerator,
        r1.denominator * r2.denominator,
    });
}

/* a1/b1 / a2/b2 = (a1 * b2) / (a2 * b1) */
rational_t divide(rational_t r1, rational_t r2) {
    return reduce((rational_t) {
        r1.numerator * r2.denominator,
        r1.denominator * r2.numerator,
    });
}

/* |a/b| = |a| / |b| */
rational_t absolute(rational_t r) {
    return (rational_t) {
        fmax(-r.numerator, r.numerator),
        fmax(-r.denominator, r.denominator),
    };
}

/* (a/b)^n = (a^n) / (b^n) */
rational_t exp_rational(rational_t r, uint16_t n) {
    return reduce( (rational_t) {
        pow(r.numerator, n),
        pow(r.denominator, n),
    }) ;
}

/* x^(a/b) = (x^(1/b))^a */
float exp_real(uint16_t x, rational_t r) {
    return pow(pow(x, 1/(float)r.denominator), r.numerator);
}

rational_t reduce(rational_t r) {
    for (int i = fmax(r.numerator, r.denominator); i > 1; i--) {
        if (r.numerator % i == 0 && r.denominator % i == 0) {
            r.numerator /= i;
            r.denominator /= i;
            break;
        }
    }
    if (r.denominator < 0) {
        r.numerator *= -1;
        r.denominator *= -1;
    }
    return r;
}
