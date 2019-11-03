def primes(limit):
    sieve = set()
    primes = list()

    for i in range(2, limit+1):
        if i not in sieve:
            primes.append(i)
            for j in range(i+i, limit+1, i):
                sieve.add(j)

    return primes

