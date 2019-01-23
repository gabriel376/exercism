def validate(fn):
    def wrapper(num):
        if num < 1 or num > 64:
            raise ValueError("invalid input")
        return fn(num)
    return wrapper

@validate
def on_square(num):
    return 1 << (num - 1)

@validate
def total_after(num):
    return (1 << num) - 1
