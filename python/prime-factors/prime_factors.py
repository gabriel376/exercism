from itertools import cycle


def candidates():
    yield 2
    yield 3
    yield 5
    candidate = 1
    for step in cycle([6, 4, 2, 4, 2, 4, 6, 2]):
        candidate += step
        yield candidate


def factors(number):
    factors = []
    for factor in candidates():
        if number == 1:
            break
        while not number % factor:
            factors.append(factor)
            number //= factor
    return factors
