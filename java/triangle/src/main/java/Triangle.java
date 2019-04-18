import java.util.Set;
import java.util.HashSet;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

class Triangle {
    private Set<Double> distinctSides = new HashSet<>();

    Triangle(double side1, double side2, double side3) throws TriangleException {
        List<Double> sides = new ArrayList<>(Arrays.asList(side1, side2, side3));

        Double max = sides.stream().max(Double::compare).get();
        Double sum = sides.stream().mapToDouble(Double::doubleValue).sum();

        if (max <= 0 || 2*max > sum) {
            throw new TriangleException();
        }

        distinctSides.addAll(sides);
    }

    boolean isEquilateral() {
       return distinctSides.size() == 1;
    }

    boolean isIsosceles() {
       return distinctSides.size() <= 2;
    }

    boolean isScalene() {
       return distinctSides.size() == 3;
    }
}
