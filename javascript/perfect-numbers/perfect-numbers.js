function * divisors(num) {
    const max = Math.floor(num/2);
    for (let x = 1; x <= max; x++) {
        if (num % x === 0) {
            yield x;
        }
    }
}

export function classify(num) {
    if (num < 1) {
        throw new Error('Classification is only possible for natural numbers.');
    }

    const sum = [...divisors(num)].reduce((a, b) => a + b, 0);

    return sum < num ? 'deficient'
         : sum > num ? 'abundant'
         : 'perfect';
}
