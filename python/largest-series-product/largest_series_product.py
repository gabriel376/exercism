from operator import mul
from functools import reduce

def largest_product(series, size):
    if size < 0:
        raise ValueError('Invalid size')

    chunks = (series[i:i+size] for i in range(len(series)-size+1))
    products = (reduce(mul, map(int, chunk), 1) for chunk in chunks)
    return max(products)
