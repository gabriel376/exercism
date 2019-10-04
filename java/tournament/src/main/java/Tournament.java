import java.util.Map;
import java.util.HashMap;
import java.util.Arrays;
import java.util.Comparator;

public class Tournament {
    private static final String FORMAT = "%-30s | %2s | %2s | %2s | %2s | %2s\n";

    private static final Comparator<Team> COMPARATOR = Comparator.comparing(Team::getPoints)
                                                                 .reversed()
                                                                 .thenComparing(Comparator.comparing(Team::getName));

    private final Map<String, Team> teams = new HashMap<>();

    public void applyResults(String results) {
        if (results == null) {
            throw new IllegalArgumentException("invalid results string");
        }

        Arrays.stream(results.split("\n"))
              .map(Result::new)
              .forEach(this::addResult);
    }

    private void addResult(Result result) {
        addTeamResult(result.getHomeTeamName(), result.getHomeTeamResult());
        addTeamResult(result.getVisitorTeamName(), result.getVisitorTeamResult());
    }

    private void addTeamResult(String name, Result.Type result) {
        teams.putIfAbsent(name, new Team(name));
        teams.get(name).applyResult(result);
    }

    private String printHeader() {
        return String.format(FORMAT, "Team",
                                     "MP",
                                     "W",
                                     "D",
                                     "L",
                                     "P");
    }

    private String printRow(Team team) {
        return String.format(FORMAT, team.getName(),
                                     team.getMatches(),
                                     team.getWins(),
                                     team.getDraws(),
                                     team.getLosses(),
                                     team.getPoints());
    }

    public String printTable() {
       return teams.values()
                   .stream()
                   .sorted(COMPARATOR)
                   .map(this::printRow)
                   .collect(StringBuilder::new,
                            StringBuilder::append,
                            StringBuilder::append)
                   .insert(0, printHeader())
                   .toString();
    }
}
