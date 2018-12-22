PLANETS =  {key: value * 31557600 for key, value in {
    'earth': 1,
    'mercury': 0.2408467,
    'venus': 0.61519726,
    'mars': 1.8808158,
    'jupiter': 11.862615,
    'saturn': 29.447498,
    'uranus': 84.016846,
    'neptune': 164.79132,
}.items()}

class SpaceAge:
    def __init__(self, seconds):
        self.seconds = seconds
        for p in PLANETS:
            func = lambda p=p: round(self.seconds / PLANETS[p], 2)
            name = 'on_%s' % p
            setattr(self, name, func)
