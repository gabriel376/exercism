import operator

classification = [(operator.lt, 'deficient'),
                  (operator.eq, 'perfect'),
                  (operator.gt, 'abundant')]

def classify(number):
    if number <= 0:
        raise ValueError('invalid input')

    factors = [n for n in range(1, number) if number % n == 0]
    aliquot_sum = sum(factors)

    return [res for ope, res in classification if ope(aliquot_sum, number)][0]
