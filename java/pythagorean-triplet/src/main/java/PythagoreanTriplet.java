public class PythagoreanTriplet {

    private int a;
    private int b;
    private int c;

    public PythagoreanTriplet(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public static PythagoreanTripletBuilder makeTripletsList() {
        return new PythagoreanTripletBuilder();
    }

    public boolean isPythagorean() {
        return a*a + b*b == c*c;
    }

    public int sum() {
        return a + b + c;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof PythagoreanTriplet) {
            PythagoreanTriplet other = (PythagoreanTriplet) obj;
            return a == other.a
                && b == other.b
                && c == other.c;
        }
        return false;
    }
}
