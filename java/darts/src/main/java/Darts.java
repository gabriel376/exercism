class Darts {
    private Dart dart;
    private Circle[] circles = {
        new Circle(0, 1, 10),
        new Circle(1, 5, 5),
        new Circle(5, 10, 1)
    };

    Darts(double x, double y) {
        this.dart = new Dart(x, y);
    }

    int score() {
        for (Circle circle : circles) {
            if (dart.hasLandedOn(circle)) {
                return circle.score();
            }
        }
        return 0;
     }
}
