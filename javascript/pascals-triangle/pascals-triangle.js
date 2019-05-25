/*
 *  Pascal's Triangle:
 *      |k=0|k=1|k=2 |k=3 |k=4 |k=5 |k=6|k=7|
 *  n=0 | 1 |   |    |    |    |    |   |   |
 *  n=1 | 1 | 1 |    |    |    |    |   |   |
 *  n=2 | 1 | 2 |  1 |    |    |    |   |   |
 *  n=3 | 1 | 3 |  3 |  1 |    |    |   |   |
 *  n=4 | 1 | 4 |  6 |  4 |  1 |    |   |   |
 *  n=5 | 1 | 5 | 10 | 10 |  5 |  1 |   |   |
 *  n=6 | 1 | 6 | 15 | 20 | 15 |  6 | 1 |   |
 *  n=7 | 1 | 7 | 21 | 35 | 35 | 21 | 7 | 1 |
 *
 *  Binomial Coefficient Formula:
 *  C(n,k) = n! / k!(n-k)!
 */

const fact = (n) => n <= 1 ? 1 : n * fact(n-1);
const binCoef = (n, k) => fact(n) / fact(k) / fact(n-k);
const getRow = (n) => Array(n+1).fill().map((_, k) => binCoef(n, k));

export class Triangle {
    constructor(num) {
        this.rows = Array(num).fill().map((_, n) => getRow(n));
        this.lastRow = this.rows.slice(-1)[0];
    }
}
