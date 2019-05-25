WIDTH = 3
HEIGHT = 4
DIGITS = [' _     _  _     _  _  _  _  _ ',
          '| |  | _| _||_||_ |_   ||_||_|',
          '|_|  ||_  _|  | _||_|  ||_| _|',
          '                              ',
]

def convert(data):
    if len(data) % HEIGHT or any(len(row) % WIDTH for row in data):
        raise ValueError('Invalid data')

    result = ''
    for i, digit in enumerate(get_digits(data)):
        result += convert_digit(digit)
        if (i + 1) * WIDTH % len(data[0]) == 0:
            result += ','

    return result[:-1]

def get_digits(data):
    for x in range(0, len(data), HEIGHT):
        for y in range(0, len(data[0]), WIDTH):
            yield [dig[y:y+WIDTH] for dig in data[x:x+HEIGHT]]

def convert_digit(digit):
    for i, val in enumerate(get_digits(DIGITS)):
        if val == digit:
            return str(i)
    return '?'
