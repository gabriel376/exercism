WIDTH = 3
HEIGHT = 4
DIGITS = [' _     _  _     _  _  _  _  _ ',
          '| |  | _| _||_||_ |_   ||_||_|',
          '|_|  ||_  _|  | _||_|  ||_| _|',
          '                              ',
]

def split_digits(data):
    for x in range(0, len(data), HEIGHT):
        for y in range(0, len(data[0]), WIDTH):
            yield [dig[y:y+WIDTH] for dig in data[x:x+HEIGHT]]

def convert_digits(digits, width):
    base = list(split_digits(DIGITS))
    check = enumerate(split_digits(digits))

    for i, digit in check:
        yield str(base.index(digit)) if digit in base else '?'
        yield ',' if (i + 1) * WIDTH % width == 0 else ''

def convert(data):
    if len(data) % HEIGHT or any(len(row) % WIDTH for row in data):
        raise ValueError('Invalid data')

    width = len(data[0])
    digits = convert_digits(data, width)
    return ''.join(digits)[:-1]
