def is_armstrong(num):
    digits = [int(d) for d in str(num)]
    exp = len(digits)
    total = sum(d**exp for d in digits)
    return total == num
