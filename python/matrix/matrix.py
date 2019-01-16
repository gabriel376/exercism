class Matrix:
    def __init__(self, m):
        self.m = [[int(n) for n in r.split()] for r in m.split('\n')]

    def row(self, i):
        return self.m[i-1]

    def column(self, i):
        return [r[i-1] for r in self.m]
