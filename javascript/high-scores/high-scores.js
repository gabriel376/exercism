export class HighScores {
    constructor(scores) {
        this.scores = scores;

        this.latest = scores[scores.length - 1];

        this.highest = Math.max(...scores);

        this.top = [...scores].sort((a, b) => b - a).slice(0, 3);

        let score = `Your latest score was ${this.latest}.`;
        let personal = this.latest == this.highest
            ? `That's your personal best!`
            : `That's ${this.highest - this.latest} short of your personal best!`;
        this.report = `${score} ${personal}`;
    }
}
