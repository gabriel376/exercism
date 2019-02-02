def saddle_points(matrix):
    if len(set(map(len, matrix))) > 1:
        raise ValueError('irregular matrix not allowed')

    t_matrix = list(zip(*matrix))

    points = [(x+1, y+1)
              for x, row in enumerate(matrix)
              for y, col in enumerate(t_matrix)
              if matrix[x][y] == max(row) and matrix[x][y] == min(col)]

    return set(points)
