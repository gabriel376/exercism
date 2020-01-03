export class Prime {
    *primes() {
        yield 2;
        for (let p = 3; true; p += 2)
            if (this.isPrime(p))
                yield p;
    }

    isPrime(p) {
        if (p % 2 === 0)
            return false;

        const max = Math.sqrt(p);
        for (let n = 3; n <= max; n += 2)
            if (p % n === 0)
                return false;

        return true;
    }

    nth(n) {
        if (n === 0)
            throw new Error('Prime is not possible');

        let count = 0;
        for (const prime of this.primes())
            if (++count === n)
                return prime;
    }
}
