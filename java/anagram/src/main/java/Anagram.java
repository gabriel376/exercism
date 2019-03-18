import java.util.List;
import java.util.ArrayList;
import java.util.stream.Collectors;

public class Anagram {
    private String word, wordArranged;

    Anagram(String word) {
        this.word = word;
        this.wordArranged = arrange(word);
    }

    List<String> match(List<String> candidates) {
        return candidates
            .stream()
            .filter(this::isAnagram)
            .collect(Collectors.toList());
    }

    private boolean isAnagram(String candidate) {
        return arrange(candidate).equals(wordArranged)
            && !candidate.equalsIgnoreCase(word);
    }

    private static String arrange(String word) {
        return word
            .toLowerCase()
            .chars()
            .sorted()
            .collect(StringBuilder::new,
                     StringBuilder::appendCodePoint,
                     StringBuilder::append)
            .toString();
    }
}
