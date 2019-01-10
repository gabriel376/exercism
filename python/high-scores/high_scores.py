class HighScores(object):
    def __init__(self, scores):
        self.scores = scores

    def latest(self):
        return self.scores[-1]

    def personal_best(self):
        return max(self.scores)

    def personal_top(self):
        return sorted(self.scores, reverse=True)[0:3]

    def report(self):
        latest = self.latest()
        best = self.personal_best()
        diff = best - latest
        result = "{} short of your personal best!".format(diff) if diff else "your personal best!"
        return "Your latest score was {}. That's {}".format(latest, result)
