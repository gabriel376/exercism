import operator

classifications = [(operator.lt, 'deficient'),
                   (operator.eq, 'perfect'),
                   (operator.gt, 'abundant')]

def classify(number):
    if number <= 0:
        raise ValueError('Classification is only possible for positive integers.')

    aliquot_sum = sum(n for n in range(1, number) if number % n == 0)

    return next(result for operation, result in classifications if operation(aliquot_sum, number))
