import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Result {
    public enum Type {WIN, LOSS, DRAW}

    private static final Pattern pattern = Pattern.compile(".+;.+;(draw|loss|win)");

    private final String homeTeamName;
    private final String visitorTeamName;

    private Type homeTeamResult;
    private Type visitorTeamResult;

    Result(String result) {
        if (!pattern.matcher(result).matches()) {
            throw new IllegalArgumentException("invalid result string");
        }

        String[] parts = result.split(";");
        homeTeamName = parts[0];
        visitorTeamName = parts[1];

        switch (parts[2]) {
        case "win":
            homeTeamResult = Type.WIN;
            visitorTeamResult = Type.LOSS;
            break;

        case "loss":
            homeTeamResult = Type.LOSS;
            visitorTeamResult = Type.WIN;
            break;

        case "draw":
            homeTeamResult = Type.DRAW;
            visitorTeamResult = Type.DRAW;
            break;
        }
    }

    public String getHomeTeamName() {
        return homeTeamName;
    }

    public String getVisitorTeamName() {
        return visitorTeamName;
    }

    public Type getHomeTeamResult() {
        return homeTeamResult;
    }

    public Type getVisitorTeamResult() {
        return visitorTeamResult;
    }
}
