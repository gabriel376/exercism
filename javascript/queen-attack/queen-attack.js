const COLS = 8;
const ROWS = 8;

const range = n => [...Array(n).keys()];

export default class Queens {
    constructor({ white: w = [0, 3], black: b = [7, 3] } = {}) {
        let white = { row: w[0], col: w[1] };
        let black = { row: b[0], col: b[1] };

        if (white.row == black.row && white.col == black.col) {
            throw new Error('Queens cannot share the same space');
        }

        this.white = [white.row, white.col];
        this.black = [black.row, black.col];
    }

    toString() {
        let white = { row: this.white[0], col: this.white[1] };
        let black = { row: this.black[0], col: this.black[1] };

        let board = range(ROWS).map(row => range(COLS).map(col => '_'));
        board[white.row][white.col] = 'W';
        board[black.row][black.col] = 'B';

        return board.map(row => row.join(' ')).join('\n') + '\n';
    }

    canAttack() {
        let white = { row: this.white[0], col: this.white[1] };
        let black = { row: this.black[0], col: this.black[1] };

        let diffRow = Math.abs(white.row - black.row);
        let diffCol = Math.abs(white.col - black.col);

        let sameRow = diffRow == 0;
        let sameCol = diffCol == 0;
        let sameDiag = diffRow == diffCol;

        return sameRow || sameCol || sameDiag;
    }
};
