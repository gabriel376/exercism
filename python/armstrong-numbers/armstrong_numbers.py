def is_armstrong(num):
    num_str = str(num)
    power = len(num_str)
    num_pow = [int(x)**power for x in str(num)]
    total = sum(num_pow)
    return total == num
