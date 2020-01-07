import { DiceResult } from './dice-result.js';

function random(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

export class Dice {
    constructor(min, max) {
        this.min = min;
        this.max = max;
    }

    roll(n) {
        const values = new Array(n).fill().map(() => random(this.min, this.max));
        return new DiceResult(values);
    }
}
