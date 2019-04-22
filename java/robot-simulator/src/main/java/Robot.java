class Robot {
    private GridPosition grid;
    private Orientation orientation;

    Robot(GridPosition grid, Orientation orientation) {
        this.grid = grid;
        this.orientation = orientation;
    }

    GridPosition getGridPosition() {
        return grid;
    }

    Orientation getOrientation() {
        return orientation;
    }

    void simulate(String command) {
        for (char c : command.toCharArray()) {
            switch (c) {
            case 'L':
                turnLeft();
                break;
            case 'R':
                turnRight();
                break;
            case 'A':
                advance();
                break;
            }
        }
    }

    void advance() {
      int x = grid.x;
      int y = grid.y;

      switch (orientation) {
        case NORTH:
            y++;
            break;
        case WEST:
            x--;
            break;
        case SOUTH:
            y--;
            break;
        case EAST:
            x++;
            break;
        }

        grid = new GridPosition(x, y);
    }

    void turnLeft() {
        switch (orientation) {
        case NORTH:
            orientation = Orientation.WEST;
            break;
        case WEST:
            orientation = Orientation.SOUTH;
            break;
        case SOUTH:
            orientation = Orientation.EAST;
            break;
        case EAST:
            orientation = Orientation.NORTH;
            break;
        }
    }

    void turnRight() {
        switch (orientation) {
        case NORTH:
            orientation = Orientation.EAST;
            break;
        case EAST:
            orientation = Orientation.SOUTH;
            break;
        case SOUTH:
            orientation = Orientation.WEST;
            break;
        case WEST:
            orientation = Orientation.NORTH;
            break;
        }
    }
}
