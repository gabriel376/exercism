import java.util.TreeMap;

class RomanNumeral {
    private static TreeMap<Integer, String> NUMERALS = new TreeMap<>();
    static {
        NUMERALS.put(1, "I");
        NUMERALS.put(4, "IV");
        NUMERALS.put(5, "V");
        NUMERALS.put(9, "IX");
        NUMERALS.put(10, "X");
        NUMERALS.put(40, "XL");
        NUMERALS.put(50, "L");
        NUMERALS.put(90, "XC");
        NUMERALS.put(100, "C");
        NUMERALS.put(400, "CD");
        NUMERALS.put(500, "D");
        NUMERALS.put(900, "CM");
        NUMERALS.put(1000, "M");
    }

    private final int number;

    RomanNumeral(int number) {
        this.number = number;
    }

    String getRomanNumeral() {
        StringBuilder result = new StringBuilder();
        int number = this.number;

        for (Integer key : NUMERALS.descendingKeySet()) {
            while (number - key >= 0) {
                result.append(NUMERALS.get(key));
                number -= key;
            }
            if (number == 0) {
                break;
            }
        }

        return result.toString();
    }
}
