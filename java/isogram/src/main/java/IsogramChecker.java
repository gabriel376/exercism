import java.util.HashSet;

class IsogramChecker {
    boolean isIsogram(String input) {
        return version3(input);
    }

    private boolean version1(String input) {
        String word = input
            .toUpperCase()
            .chars()
            .filter(Character::isLetter)
            .collect(StringBuilder::new,
                     StringBuilder::appendCodePoint,
                     StringBuilder::append)
            .toString();
        return word.chars().distinct().count() == word.length();
    }

    private boolean version2(String input) {
        String word = input.toUpperCase();
        return word
            .chars()
            .filter(Character::isLetter)
            .allMatch(c -> word.indexOf(c) == word.lastIndexOf(c));
    }

    private boolean version3(String input) {
        HashSet<Integer> set = new HashSet<>();
        return input
            .toUpperCase()
            .chars()
            .filter(Character::isLetter)
            .allMatch(set::add);
    }
}

