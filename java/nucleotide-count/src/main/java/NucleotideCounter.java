import java.util.Map;
import java.util.HashMap;

class NucleotideCounter {
    private static char[] nucleotides = {'A', 'C', 'G', 'T'};
    private Map<Character, Integer> counter = new HashMap<>();

    NucleotideCounter(String strand) {
        for (char nuc : nucleotides) {
            counter.put(nuc, 0);
        }

        for (char nuc : strand.toCharArray()) {
            if (!counter.containsKey(nuc)) {
                throw new IllegalArgumentException();
            }
            counter.put(nuc, counter.get(nuc) + 1);
        }
    }

    Map<Character, Integer> nucleotideCounts() {
        return counter;
    }
}
