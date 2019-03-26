class LuhnValidator {
    boolean isValid(String input) {
        int sum = 0;
        int count = 0;

        for (char c : input.toCharArray()) {
            if (Character.isSpaceChar(c)) {
                continue;
            }

            if (!Character.isDigit(c)) {
                return false;
            }

            int num = Character.getNumericValue(c);

            if (count % 2 == input.length() % 2) {
                num *= 2;
            }

            if (num > 9) {
                num -= 9;
            }

            sum += num;
            count++;
        }

        return count > 1 && sum % 10 == 0;
    }
}
