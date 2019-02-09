import math

SCORES = {
    # radius: score
    1: 10,
    5: 5,
    10: 1,
}
def score(x, y):
    distance = math.sqrt(x*x + y*y)
    result = [sco for rad, sco in SCORES.items() if distance <= rad] or [0]
    return result[0]
