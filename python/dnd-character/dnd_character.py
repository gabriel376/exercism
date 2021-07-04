import math
import random
import heapq

class Dice():
    def __init__(self, high, rand=random):
        self.high = high
        self.rand = rand

    def roll(self, qty):
        values = [self.rand.randint(1, self.high) for _ in range(0, qty)]
        return DiceValues(values)

class DiceValues():
    def __init__(self, values):
        self.values = values

    def top(self, n):
        return DiceValues(heapq.nlargest(n, self.values))

    def sum(self):
        return sum(self.values)

class Character:
    def __init__(self):
        for a in self.abilities():
            setattr(self, a, self.ability())

        self.hitpoints = 10 + modifier(self.constitution)

    def ability(self):
        return Dice(6).roll(4).top(3).sum()

    def abilities(self):
        return ['strength',
                'dexterity',
                'constitution',
                'intelligence',
                'wisdom',
                'charisma',
        ]

def modifier(constitution):
    return math.floor((constitution - 10) / 2)
