import java.util.List;
import java.util.Arrays;
import java.util.Collections;
import java.util.stream.IntStream;
import java.util.stream.Collectors;

class TwelveDays {
    static String START = "On the %s day of Christmas my true love gave to me: ";

    static List<String> ORDINALS = Arrays.asList(
        "first",
        "second",
        "third",
        "fourth",
        "fifth",
        "sixth",
        "seventh",
        "eighth",
        "ninth",
        "tenth",
        "eleventh",
        "twelfth");

    static List<String> GIFTS = Arrays.asList(
        "a Partridge in a Pear Tree.",
        "two Turtle Doves, and ",
        "three French Hens, ",
        "four Calling Birds, ",
        "five Gold Rings, ",
        "six Geese-a-Laying, ",
        "seven Swans-a-Swimming, ",
        "eight Maids-a-Milking, ",
        "nine Ladies Dancing, ",
        "ten Lords-a-Leaping, ",
        "eleven Pipers Piping, ",
        "twelve Drummers Drumming, ");

    String verse(int index) {
        return new StringBuilder(String.format(START, ORDINALS.get(index-1)))
            .append(IntStream.range(0, index)
                .boxed()
                .sorted(Collections.reverseOrder())
                .map(GIFTS::get)
                .collect(Collectors.joining("")))
            .append("\n")
            .toString();
    }

    String verses(int from, int to) {
        return IntStream.rangeClosed(from, to)
            .mapToObj(this::verse)
            .collect(Collectors.joining("\n"));
    }

    String sing() {
        return verses(1, GIFTS.size());
    }
}
