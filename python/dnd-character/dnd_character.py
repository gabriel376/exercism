import math
import random
import heapq

class Dice():
    def __init__(self, min, max):
        self.min = min
        self.max = max

    def roll(self, qty):
        values = [random.randint(self.min, self.max) for _ in range(0, qty)]
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
        return Dice(1, 6).roll(4).top(3).sum()

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
