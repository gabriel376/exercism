function * generate(number) {
    for (let divisor = 2; number > 1; divisor++) {
        while (number % divisor == 0) {
            number /= divisor;
            yield divisor;
        }
    }
}

export const primeFactors = (n) => [...generate(n)];
