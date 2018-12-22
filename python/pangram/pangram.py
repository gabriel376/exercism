from string import ascii_lowercase

ALL_LETTERS = set(ascii_lowercase)

def is_pangram(string):
    return ALL_LETTERS.issubset(string.lower())
