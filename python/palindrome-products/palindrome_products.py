def smallest_palindrome(min_factor, max_factor):
    return get_palindrome(min_factor, max_factor, False)

def largest_palindrome(min_factor, max_factor):
    return get_palindrome(min_factor, max_factor, True)

def get_palindrome(low, high, rev):
    palindrome = 0
    factors = []
    multiples = range(low**2, high**2+1)

    if rev:
        multiples = reversed(multiples)

    for x in multiples:
        if str(x) == str(x)[::-1]:
            palindrome = x
            factors = [(y, x/y) for y in range(low, high+1) if x%y==0 and low <= x/y <= high]
            if factors:
                return palindrome, factors

    raise ValueError("could not find any valid palindrome")
