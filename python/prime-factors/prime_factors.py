from itertools import cycle

def prime_candidates():
    yield 2
    yield 3
    yield 5
    candidate = 1
    for step in cycle([6, 4, 2, 4, 2, 4, 6, 2]):
        candidate += step
        yield candidate

def prime_factors(number):
    candidates = prime_candidates()
    factors = []
    factor = next(candidates)
    while number > 1:
        while not number % factor:
            factors += [factor]
            number //= factor
        factor = next(candidates)
    return factors
