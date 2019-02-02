def saddle_points(matrix):
    points = []

    if len(set(map(len, matrix))) > 1:
        raise ValueError('irregular matrix not allowed')

    for x, row in enumerate(matrix):
        for y, value in enumerate(row):
            col = [r[y] for r in matrix]
            if value == max(row) and value == min(col):
                point = (x+1, y+1)
                points.append(point)

    return set(points)

