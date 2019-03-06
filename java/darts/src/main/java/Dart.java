class Dart {
    private double x, y;

    Dart(double x, double y) {
        this.x = x;
        this.y = y;
    }

    double distance() {
        return Math.sqrt(x*x + y*y);
    }

    boolean hasLandedOn(Circle circle) {
        return distance() >= circle.min() && distance() <= circle.max();
    }
}
