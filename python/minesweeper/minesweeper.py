MINE = '*'
ADJACENTS = [
    [-1, -1], [-1, 0], [-1, +1],
    [ 0, -1],          [ 0, +1],
    [+1, -1], [+1, 0], [+1, +1],
]

def annotate(board):
    invalid_fields = [field for row in board for field in row if field not in [' ', MINE]]
    if invalid_fields:
        raise ValueError('invalid field(s): ' + str(invalid_fields))

    lengths = [len(row) for row in board]
    if len(set(lengths)) != 1 and board:
        raise ValueError('invalid length(s): ' + str(lengths))
    
    def is_mine(row, col):
        return 0 <= row < len(board) and 0 <= col < len(board[row]) and board[row][col] == MINE
        
    def annotate_field(row, col):
        if board[row][col] == MINE:
            return MINE

        count = sum(1 for [r, c] in ADJACENTS if is_mine(row+r, col+c))
        return ' ' if count == 0 else str(count)
        
    def annotate_row(row):
        return ''.join(annotate_field(row, col) for col in range(0, len(board[row])))
        
    return [annotate_row(row) for row in range(0, len(board))]
