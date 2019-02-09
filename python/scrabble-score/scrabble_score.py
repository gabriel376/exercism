SCORES = {
    1: 'AEIOULNRST',
    2: 'DG',
    3: 'BCMP',
    4: 'FHVWY',
    5: 'K',
    8: 'JX',
    10: 'QZ',
}

SCORES = {score: letters.upper() + letters.lower() for score, letters in SCORES.items()}
SCORES = {letter: score for score, letters in SCORES.items() for letter in letters}

def score(word):
    return sum(SCORES[letter] for letter in word if letter.isalpha())
