import java.util.Map;
import java.util.HashMap;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class WordCount {
    private static final Pattern pattern = Pattern.compile("(\\w+(?:'\\w)?)");

    public Map<String, Integer> phrase(String text) {
        Map<String, Integer> words = new HashMap<>();
        Matcher matcher = pattern.matcher(text.toLowerCase());

        while (matcher.find()) {
            String word = matcher.group(0);
            Integer count = words.getOrDefault(word, 0);
            words.put(word, count + 1);
        }

        return words;
    }
}
