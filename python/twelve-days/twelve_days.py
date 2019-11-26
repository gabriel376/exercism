ORDINALS = [
    'first',
    'second',
    'third',
    'fourth',
    'fifth',
    'sixth',
    'seventh',
    'eighth',
    'ninth',
    'tenth',
    'eleventh',
    'twelfth',
]

GIFTS = [
    'a Partridge in a Pear Tree.',
    'two Turtle Doves',
    'three French Hens',
    'four Calling Birds',
    'five Gold Rings',
    'six Geese-a-Laying',
    'seven Swans-a-Swimming',
    'eight Maids-a-Milking',
    'nine Ladies Dancing',
    'ten Lords-a-Leaping',
    'eleven Pipers Piping',
    'twelve Drummers Drumming',
]

VERSE = 'On the {} day of Christmas my true love gave to me: {}{}{}'

def get_verse(n):
    return VERSE.format(
        ORDINALS[n-1],
        ', '.join(GIFTS[1:n][::-1]),
        ', and ' if n > 1 else '',
        GIFTS[0])

def recite(start, end):
    return [get_verse(n) for n in range(start, end+1)]
