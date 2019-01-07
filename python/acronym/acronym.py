import re

pattern = re.compile(r"\w+\'?\w?")

def abbreviate(text):
    words = pattern.findall(text)
    acronym = [w[0] for w in words]
    return ''.join(acronym).upper()
