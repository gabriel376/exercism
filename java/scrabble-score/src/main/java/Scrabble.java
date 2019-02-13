import java.util.Map;

class Scrabble {
    private static final Map<Integer, Integer> SCORES = Scores.get();
    private int score = 0;

    Scrabble(String word) {
        this.score = word.chars().map(SCORES::get).sum();
    }

    int getScore() {
        return this.score;
    }
}
