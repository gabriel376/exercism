class MatrixCoordinate implements Comparable<MatrixCoordinate> {

    private final int row;
    private final int col;

    public MatrixCoordinate(int row, int col) {
        this.row = row;
        this.col = col;
    }

    public int getRow() {
        return row;
    }

    public int getCol() {
        return col;
    }

    @Override
    public String toString() {
        return String.format("Row: %d, Column: %d", row, col);
    }

    @Override
    public boolean equals(final Object obj) {
        if (obj == this) {
            return true;
        }

        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }

        final MatrixCoordinate other = (MatrixCoordinate) obj;
        return row == other.row && col == other.col;
    }

    @Override
    public int hashCode() {
        return 31 * row + col;
    }

    @Override
    public int compareTo(MatrixCoordinate other) {
        int rowComparison = Integer.compare(row, other.row);
        return rowComparison == 0
            ? Integer.compare(col, other.col)
            : rowComparison;
    }
}
