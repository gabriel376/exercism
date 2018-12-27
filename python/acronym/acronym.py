def abbreviate(text):
    words = text.upper().replace('-', ' ').split()
    return ''.join([w[0] for w in words])
