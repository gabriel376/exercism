export class Palindromes {
    static generate({ minFactor, maxFactor }) {
        if (minFactor > maxFactor) {
            throw new Error('min must be <= max');
        }

        const result = {
            smallest: new Result(),
            largest: new Result(),
        };

        const minProduct = minFactor ** 2;
        const maxProduct = maxFactor ** 2;
        const diff = maxProduct - minProduct;

        for (let i = 0; i < diff; i++) {
            const smallProduct = minProduct + i;
            const largeProduct = maxProduct - i;

            if (!result.smallest.done()){
                result.smallest = getPalindrome(minFactor, maxFactor, smallProduct);
            }

            if (!result.largest.done()) {
                result.largest = getPalindrome(minFactor, maxFactor, largeProduct);
            }

            if (result.smallest.done() && result.largest.done()) {
                break;
            }
        }

        return result;
    }
}

class Result {
    constructor(value=null, factors=[]) {
        this.value = value;
        this.factors = factors;
    }

    done() {
        return this.factors.length > 0;
    }
}

function getPalindrome(min, max, prod) {
    if (!isPalindrome(prod)) {
        return new Result();
    }

    const factors = [];

    for (let i = min; i <= max; i++) {
        const div = prod / i;
        if (prod % i === 0 && div <= max && div >= i) {
            factors.push([i, div]);
        }
    }

    return new Result(prod, factors);
}

function isPalindrome(num) {
    const str = String(num);
    return str === [...str].reverse().join('');
}

