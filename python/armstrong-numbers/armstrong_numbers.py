def is_armstrong(num):
    num_str = str(num)
    exp = len(num_str)
    total = sum([int(x)**exp for x in num_str])
    return total == num
