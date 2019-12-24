#ifndef SIEVE_H
#define SIEVE_H

#include <stdint.h>
#include <stddef.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes);

#endif
