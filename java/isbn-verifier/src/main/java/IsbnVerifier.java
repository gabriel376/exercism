class IsbnVerifier {
    boolean isValid(String input) {
        int sum = 0;
        int pos = 10;

        for (char c : input.toCharArray()) {
            int num = 0;

            if (Character.isDigit(c)) {
                num = Character.digit(c, 10);

            } else if (c == 'X' && pos == 1) {
                num = 10;

            } else {
                continue;
            }

            sum += num * pos--;
        }

        return pos == 0 && sum % 11 == 0;
    }
}
