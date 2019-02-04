from string import ascii_uppercase as letters
from string import digits
from random import shuffle
from itertools import product

base = [letters, letters, digits, digits, digits]
names = list(product(*base))
shuffle(names)

class Robot(object):
    def __init__(self):
        self.reset()

    def reset(self):
        if not names:
            raise ValueError('All possible names have been created.')
        self.name = ''.join(names.pop())


