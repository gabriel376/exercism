CODES = [
    'black',
    'brown',
    'red',
    'orange',
    'yellow',
    'green',
    'blue',
    'violet',
    'grey',
    'white',
]

def value(colors):
    codes = [CODES.index(color) for color in colors[:2]]
    return sum(code * 10**i for i, code in enumerate(reversed(codes)))
