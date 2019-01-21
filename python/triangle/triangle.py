def is_triangle(fn):
    return lambda s: fn(s) and all(s) and 2*max(s) < sum(s)

@is_triangle
def is_equilateral(sides):
    return len(set(sides)) == 1

@is_triangle
def is_isosceles(sides):
    return len(set(sides)) <= 2

@is_triangle
def is_scalene(sides):
    return len(set(sides)) == 3
