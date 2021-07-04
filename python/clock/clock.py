DAY = 24 * 60

class Clock:
    def __init__(self, hour, minute):
        self.minutes = ((((hour * 60) + minute) % DAY) + DAY) % DAY

    def __repr__(self):
        h = self.minutes // 60
        m = self.minutes % 60
        return f"{h:02}:{m:02}"

    def __eq__(self, other):
        return self.minutes == other.minutes

    def __add__(self, minutes):
        return Clock(0, self.minutes + minutes)

    def __sub__(self, minutes):
        return Clock(0, self.minutes - minutes)
