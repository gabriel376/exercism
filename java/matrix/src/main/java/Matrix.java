class Matrix {
    int[][] rows, cols;

    Matrix(String matrix) {
        String[] lines = matrix.split("\n");

        int height = lines.length;
        int width = lines[0].split(" ").length;

        rows = new int[height][width];
        cols = new int[width][height];

        for (int x = 0; x < lines.length; x++) {
            String[] numbers = lines[x].split(" ");
            for (int y = 0; y < numbers.length; y++) {
                rows[x][y] = cols[y][x] = Integer.parseInt(numbers[y]);
            }
        }
    }

    int[] getRow(int index) {
        return rows[index];
    }

    int[] getColumn(int index) {
        return cols[index];
    }
}
