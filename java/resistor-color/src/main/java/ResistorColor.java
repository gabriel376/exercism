import java.util.NoSuchElementException;

class ResistorColor {
    private final static String[] COLORS = new String[] {
        "black",
        "brown",
        "red",
        "orange",
        "yellow",
        "green",
        "blue",
        "violet",
        "grey",
        "white",
    };

    int colorCode(String color) {
        for (int i = 0; i < COLORS.length; i++) {
            if (COLORS[i].equals(color)) {
                return i;
            }
        }
        throw new NoSuchElementException();
    }

    String[] colors() {
        return COLORS;
    }
}
