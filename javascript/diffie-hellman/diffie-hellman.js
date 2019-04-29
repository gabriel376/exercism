function isPrime(n) {
    for (var i = 2; i <= Math.sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

export class DiffieHellman {
    constructor(p, g) {
        if (p <= 0 || g <= 0) {
            throw new Error('arguments must be greater than zero');
        }

        if (!isPrime(p) || !isPrime(g)) {
            throw new Error('arguments must be prime numbers');
        }

        this.p = p;
        this.g = g;
    }

    getPublicKeyFromPrivateKey(a) {
        if (a <= 1 || a >= this.p) {
            throw new Error(`argument must be between 2 and ${this.p-1}`);
        }

        return (this.g ** a) % this.p;
    }

    getSharedSecret(a, b) {
        return (b ** a) % this.p;
    }
}
