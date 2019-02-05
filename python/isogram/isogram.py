def is_isogram(string):
    alphas = list(filter(str.isalpha, string.lower()))
    return len(set(alphas)) == len(alphas)
