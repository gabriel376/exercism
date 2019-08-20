LYRICS = [
    ['first',    'a Partridge in a Pear Tree.'],
    ['second',   'two Turtle Doves'],
    ['third',    'three French Hens'],
    ['fourth',   'four Calling Birds'],
    ['fifth',    'five Gold Rings'],
    ['sixth',    'six Geese-a-Laying'],
    ['seventh',  'seven Swans-a-Swimming'],
    ['eighth',   'eight Maids-a-Milking'],
    ['ninth',    'nine Ladies Dancing'],
    ['tenth',    'ten Lords-a-Leaping'],
    ['eleventh', 'eleven Pipers Piping'],
    ['twelfth',  'twelve Drummers Drumming'],
]

ORDINALS = [line[0] for line in LYRICS]
GIFTS =    [line[1] for line in LYRICS]

def get_verse(n):
    verse = 'On the {} day of Christmas my true love gave to me: {}{}{}'
    return verse.format(
        ORDINALS[n-1],
        ', '.join(GIFTS[1:n][::-1]),
        ', and ' if n > 1 else '',
        GIFTS[0])

def recite(start, end):
    return [get_verse(n) for n in range(start, end+1)]
