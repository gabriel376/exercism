def square(num):
    if num < 1 or num > 64:
        raise ValueError("square must be between 1 and 64")
    return 1 << (num - 1)

def total():
    return (1 << 64) - 1
