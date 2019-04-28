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

    public String printTable() {
        StringBuilder table = new StringBuilder();

        table.append(String.format(FORMAT, "Team",
                                           "MP",
                                           "W",
                                           "D",
                                           "L",
                                           "P"));

        if (teams.isEmpty()) {
            return table.toString();
        }

        Comparator<Team> comparator = Comparator.comparing(Team::getPoints)
                                                .reversed()
                                                .thenComparing(Comparator.comparing(Team::getName));

       teams.values()
            .stream()
            .sorted(COMPARATOR)
            .forEach(team -> table.append(team.print(FORMAT)));

        return table.toString();
    }
}
