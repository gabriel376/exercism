export class DiceResult {
    constructor(values) {
        this.values = values;
    }

    top(n) {
        this.values = this.values.sort((a, b) => b - a).slice(0, n);
        return this;
    }

    sum() {
        return this.values.reduce((a, b) => a + b);
    }
}
