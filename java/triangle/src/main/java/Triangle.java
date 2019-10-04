import java.util.Arrays;
import java.util.List;

class Triangle {
    private double min, mid, max;

    Triangle(double a, double b, double c) throws TriangleException {
        List<Double> sides = Arrays.asList(a, b, c);
        sides.sort(Double::compare);

        min = sides.get(0);
        mid = sides.get(1);
        max = sides.get(2);

        if (min <= 0 || max > min + mid) {
            throw new TriangleException();
        }
    }

    boolean isEquilateral() {
       return min == max;
    }

    boolean isIsosceles() {
       return min == mid || mid == max;
    }

    boolean isScalene() {
       return min != mid && mid != max;
    }
}
