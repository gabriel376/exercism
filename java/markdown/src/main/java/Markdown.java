import java.util.Arrays;
import java.util.stream.Collectors;

class Markdown {
    String parse(String markdown) {
        return Arrays.stream(markdown.split("\n"))
            .map(this::parseLine)
            .collect(Collectors.joining())
            .replaceAll("</ul><ul>", "");
    }

    private String parseLine(String line) {
        line = parseEmphasis(line);
        switch (line.charAt(0)) {
            case '#': return parseHeader(line);
            case '*': return parseListItem(line);
            default:  return parseParagraph(line);
        }
    }

    private String parseHeader(String markdown) {
        int count = (int) markdown.chars().takeWhile(c -> c == '#').count();
        String content = markdown.substring(count + 1);
        return String.format("<h%d>%s</h%d>", count, content, count);
    }

    private String parseListItem(String markdown) {
        return String.format("<ul><li>%s</li></ul>", markdown.substring(2));
    }

    private String parseParagraph(String markdown) {
        return String.format("<p>%s</p>", markdown);
    }

    private String parseEmphasis(String markdown) {
        return markdown.replaceAll("__(.+)__", "<strong>$1</strong>")
                       .replaceAll("_(.+)_", "<em>$1</em>");
    }
}
