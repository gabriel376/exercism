class HighScores(object):
    def __init__(self, scores):
        self.scores = scores

    def latest(self):
        return self.scores[-1]

    def personal_best(self):
        return max(self.scores)

    def personal_top(self):
        return sorted(self.scores, reverse=True)[:3]

    def report(self):
        latest = self.latest()
        best = self.personal_best()
        diff = best - latest

        score = "Your latest score was {}.".format(latest)
        short = "That's {} short of your personal best!".format(diff)
        best = "That's your personal best!"

        return "{} {}".format(score, short if diff else best)
