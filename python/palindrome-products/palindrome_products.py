def smallest(min_factor, max_factor):
    return calculate(min_factor, max_factor, False)

def largest(min_factor, max_factor):
    return calculate(min_factor, max_factor, True)

def calculate(low, high, rev):
    if low > high:
        raise ValueError("min must be <= max")

    multiples = range(low**2, high**2+1)
    if rev:
        multiples = reversed(multiples)

    for x in multiples:
        if str(x) == str(x)[::-1]:
            factors = [(y, x/y) for y in range(low, high+1) if x%y==0 and low <= x/y <= high]
            if factors:
                return x, factors

    return None, []
