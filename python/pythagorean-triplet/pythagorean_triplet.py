def triplets_with_sum(total):
    triplets = []
    for a in range(1, total):
        b = int((pow(total - a, 2) - pow(a, 2)) / (2 * (total - a)))
        c = total - a - b
        if a < b and pow(a, 2) + pow(b, 2) == pow(c, 2):
            triplets.append([a, b, c])
    return triplets
