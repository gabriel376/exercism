class Squares {
    squareOfSum: number;
    sumOfSquares: number;
    difference: number;

    constructor(max: number) {
        let array = [...Array(max).keys()].map(x => x + 1);
        this.squareOfSum = Math.pow(array.reduce((acc, cur) => acc + cur, 0), 2);
        this.sumOfSquares = array.reduce((acc, cur) => acc + Math.pow(cur, 2), 0);
        this.difference = this.squareOfSum - this.sumOfSquares;
    }
}

export default Squares;
