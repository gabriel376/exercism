from re import compile
from collections import Counter

ALL_WORDS = compile(r"[a-zA-Z0-9]+(\'[a-z])?")

def word_count(input):
    matches = ALL_WORDS.finditer(input.lower())
    return Counter(match.group() for match in matches)
