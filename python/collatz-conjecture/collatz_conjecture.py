def collatz_steps(num):
    if num <= 0:
        raise ValueError("Number must be greater than 0")

    steps = 0
    while num > 1:
        steps += 1
        num = (num * 3) + 1 if num % 2 else num / 2

    return steps
