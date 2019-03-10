STUDENTS = [
    'Alice',
    'Bob',
    'Charlie',
    'David',
    'Eve',
    'Fred',
    'Ginny',
    'Harriet',
    'Ileana',
    'Joseph',
    'Kincaid',
    'Larry',
]

SEEDS = [
    'Clover',
    'Grass',
    'Radishes',
    'Violets',
]

class Garden(object):
    def __init__(self, diagram, students=STUDENTS, seeds=SEEDS, cups=2):
        self.diagram = diagram.split('\n')
        self.students = sorted(students)
        self.seeds = {seed[0]: seed for seed in seeds}
        self.cups = cups

    def plants(self, student):
        start = self.students.index(student) * self.cups
        end = start + self.cups
        return [self.seeds[seed] for row in self.diagram for seed in row[start:end]]
