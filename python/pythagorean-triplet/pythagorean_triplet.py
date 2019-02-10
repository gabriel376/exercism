def triplets_with_sum(total):
    return set(pythagorean_triplets(total))

def pythagorean_triplets(total):
    for a in range(1, total):
        b = (pow(total - a, 2) - pow(a, 2)) / (2 * (total - a))
        c = total - a - b

        if a < b and b == int(b) and a*a + b*b == c*c:
            yield (a, b, c)
