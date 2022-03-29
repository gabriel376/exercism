ALLERGENS = [
    'eggs',
    'peanuts',
    'shellfish',
    'strawberries',
    'tomatoes',
    'chocolate',
    'pollen',
    'cats',
]

class Allergies:
    def __init__(self, score):
        self.lst = [v for i, v in enumerate(ALLERGENS) if 2**i & score]

    def allergic_to(self, item):
        return item in self.lst
