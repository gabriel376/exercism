import java.util.Map;
import java.util.HashMap;
import java.util.Collections;

class Scores {
    private static Map<Integer, Integer> SCORES = new HashMap<Integer, Integer>();

    static {
        add("AEIOULNRST", 1);
        add("DG", 2);
        add("BCMP", 3);
        add("FHVWY", 4);
        add("K", 5);
        add("JX", 8);
        add("QZ", 10);
    }

    private static void add(String string, Integer score) {
        string.chars().forEach(c -> {
                SCORES.put(Character.toLowerCase(c), score);
                SCORES.put(Character.toUpperCase(c), score);
            });
    }

    public static Map<Integer, Integer> get() {
        return Collections.unmodifiableMap(SCORES);
    }
}
