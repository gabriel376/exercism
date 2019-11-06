export const primes = (max) => {
    const sieve = [];
    const result = [];

    for (let i = 2; i <= max; i++) {
        if (!sieve[i]) {
            result.push(i);
        }

        for (let j = i; j <= max; j += i) {
            sieve[j] = true;
        }
    }

    return result;
};
