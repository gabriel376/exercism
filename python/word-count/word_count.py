from re import compile
from collections import Counter

PATTERN = compile(r"[a-zA-Z0-9]+(\'[a-z])?")

def word_count(input):
    matches = PATTERN.finditer(input.lower())
    words = [match.group() for match in matches]
    return Counter(words)
