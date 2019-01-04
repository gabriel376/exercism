const MINE = '*';
const ADJACENTS = [
    [-1, -1], [-1, 0], [-1, +1],
    [ 0, -1],          [ 0, +1],
    [+1, -1], [+1, 0], [+1, +1],
];

export const annotate = (board) => {
    return board.map((_, row) =>
        Array.from(board[row]).map((_, col) => {
            if (board[row][col] == MINE)
                return MINE;

            let count = ADJACENTS.reduce((acc, [x, y]) =>
                board[row + x] && board[row + x][col + y] == MINE
                    ? acc + 1
                    : acc
            , 0);

            return count == 0 ? ' ' : String(count);
        }).join(''));
};
