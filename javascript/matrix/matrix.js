export class Matrix {
    constructor(matrix) {
        this.rows = matrix.split("\n").map(row => row.split(" ").map(Number));
        this.columns = this.rows.map((_, col) => this.rows.map(row => row[col]));
  }
}
