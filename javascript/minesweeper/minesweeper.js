const MINE = '*';
const ADJACENTS = [
    [-1, -1], [-1, 0], [-1, +1],
    [ 0, -1],          [ 0, +1],
    [+1, -1], [+1, 0], [+1, +1],
];

export const annotate = (board) => {
    const isMine = (row, col) => board[row] && board[row][col] == MINE;

    const annotateRow = row => [...board[row]].map((_, col) => annotateField(row, col)).join('');

    const annotateField = (row, col) => {
	if (isMine(row, col)) return MINE;
	const count = ADJACENTS.filter(([r, c]) => isMine(row+r, col+c)).length;
	if (count === 0) return ' ';
	return String(count);
    }

    return board.map((_, row) => annotateRow(row));
};
