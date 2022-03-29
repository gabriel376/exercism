def saddle_points(matrix):
    if len(set(map(len, matrix))) > 1:
        raise ValueError('irregular matrix')

    t_matrix = list(zip(*matrix))

    return [{"row": x+1, "column": y+1}
            for x, row in enumerate(matrix)
            for y, col in enumerate(t_matrix)
            if matrix[x][y] == max(row) and matrix[x][y] == min(col)]
