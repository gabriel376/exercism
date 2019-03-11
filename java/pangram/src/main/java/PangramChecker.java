public class PangramChecker {
    private static final long LETTERS_IN_ALPHABET = 26;

    public boolean isPangram(String input) {
        return input
            .toLowerCase()
            .chars()
            .filter(Character::isLetter)
            .distinct()
            .count() == LETTERS_IN_ALPHABET;
    }
}
