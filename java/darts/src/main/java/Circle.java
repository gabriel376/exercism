class Circle {
    private double min, max;
    private int score;

    Circle(double min, double max, int score) {
        this.min = min;
        this.max = max;
        this.score = score;
    }

    double min() {
        return min;
    }

    double max() {
        return max;
    }

    int score() {
        return score;
    }
}
