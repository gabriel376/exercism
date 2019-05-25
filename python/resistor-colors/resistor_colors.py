COLORS = [
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
    codes = [COLORS.index(color) for color in colors]
    return sum(code * 10**i for i, code in enumerate(reversed(codes)))
