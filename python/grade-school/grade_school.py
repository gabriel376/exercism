from collections import defaultdict

class School:
    def __init__(self):
        self.database = defaultdict(set)

    def add_student(self, name, grade):
        self.database[grade].add(name)

    def roster(self):
        return [name
                for grade in sorted(self.database)
                for name in self.grade(grade)]

    def grade(self, grade):
        return sorted(self.database[grade])
