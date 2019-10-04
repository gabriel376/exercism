public class Team {
    private final String name;

    private Integer wins = 0;
    private Integer draws = 0;
    private Integer losses = 0;

    Team(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void applyResult(Result.Type result) {
        switch (result) {
        case WIN:
            wins++;
            break;

        case LOSS:
            losses++;
            break;

        case DRAW:
            draws++;
            break;
        }
    }

    public Integer getWins() {
        return wins;
    }

    public Integer getLosses() {
        return losses;
    }

    public Integer getDraws() {
        return draws;
    }

    public Integer getMatches() {
        return getWins() + getDraws() + getLosses();
    }

    public Integer getPoints() {
        return 3*getWins() + getDraws();
    }
}
