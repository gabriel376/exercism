def sum_of_multiples(limit, multiples):
    return sum({x for m in multiples if m for x in range(m, limit, m)})
