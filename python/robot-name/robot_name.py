from itertools import product
from random import shuffle
from string import ascii_uppercase, digits


class RobotNames():
    _all_names = [''.join(chars) for chars in product(*[
        ascii_uppercase,
        ascii_uppercase,
        digits,
        digits,
        digits,
    ])]

    def __init__(self):
        names = self._all_names.copy()
        shuffle(names)
        self._names = iter(names)

    def __next__(self):
        return next(self._names)


class Robot():
    def __init__(self):
        self._names = RobotNames()
        self.reset()

    def reset(self):
        self.name = next(self._names)
