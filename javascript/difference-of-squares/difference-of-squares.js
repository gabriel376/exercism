Array.range = function(max) {
    return [...Array(max).keys()].map(x => x + 1);
}

Array.prototype.sum = function() {
    return this.reduce((x, y) => x + y);
}

Array.prototype.square = function() {
    return this.map(x => x * x);
}

export class Squares {
    constructor(max) {
        this.squareOfSum = Array.range(max).sum() ** 2;
        this.sumOfSquares = Array.range(max).square().sum();
        this.difference = this.squareOfSum - this.sumOfSquares;
    }
}
