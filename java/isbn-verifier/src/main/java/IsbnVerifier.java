class IsbnVerifier {
    boolean isValid(String input) {
        int sum = 0;
        int pos = 10;

        for (char c : input.toCharArray()) {
            if (Character.isDigit(c)) {
                sum += Character.digit(c, 10) * pos--;
            } else if (c == 'X' && pos == 1) {
                sum += 10 * pos--;
            }
        }

        return pos == 0 && sum % 11 == 0;
    }
}
