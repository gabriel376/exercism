import BigInt from './lib/big-integer';

export class Grains {
    square(num) {
        return BigInt(2).pow(num-1).toString();
    }

    total() {
        return BigInt(2).pow(64).subtract(1).toString();
    }
}
