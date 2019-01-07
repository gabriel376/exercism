import re

PATTERN = re.compile(r"(?:^| |-)([a-zA-Z])")

def abbreviate(text):
    acronym = PATTERN.findall(text)
    return ''.join(acronym).upper()
