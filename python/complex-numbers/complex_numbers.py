from math import exp, cos, sin

class ComplexNumber(object):
    def __init__(self, real, imaginary):
        self.real = real
        self.imaginary = imaginary

    def __repr__(self):
        return "{} + {}i".format(self.real, self.imaginary)

    def __eq__(self, other):
        return self.real == other.real and self.imaginary == other.imaginary

    def __add__(self, other):
        return ComplexNumber(
            self.real + other.real,
            self.imaginary + other.imaginary
        )

    def __mul__(self, other):
        return ComplexNumber(
            self.real * other.real - self.imaginary * other.imaginary,
            self.real * other.imaginary + self.imaginary * other.real
        )

    def __sub__(self, other):
        return ComplexNumber(
            self.real - other.real,
            self.imaginary - other.imaginary
        )

    def __truediv__(self, other):
        conjugate = other.conjugate()
        dividend = self * conjugate
        divisor = other * conjugate
        return ComplexNumber(
            dividend.real / divisor.real,
            dividend.imaginary / divisor.real
        )

    def __abs__(self):
        return (self.real ** 2 + self.imaginary ** 2) ** (1 / 2)

    def conjugate(self):
        return ComplexNumber(
            self.real,
            -1 * self.imaginary
        )

    def exp(self):
        return ComplexNumber(
            exp(self.real) * cos(self.imaginary),
            exp(self.real) * sin(self.imaginary)
        )
