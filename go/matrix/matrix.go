package matrix

import (
	"errors"
	"strconv"
	"strings"
)

type Matrix [][]int

// New creates a Matrix from string.
func New(input string) (Matrix, error) {
	var matrix Matrix
	for i, r := range strings.Split(input, "\n") {
		var row []int
		for _, c := range strings.Split(strings.TrimSpace(r), " ") {
			num, err := strconv.Atoi(c)
			if err != nil {
				return nil, errors.New("Invalid number")
			}
			row = append(row, num)
		}
		matrix = append(matrix, row)
		if len(matrix[0]) != len(matrix[i]) {
			return nil, errors.New("Invalid matrix geometry")
		}
	}
	return matrix, nil
}

// Rows returns the Matrix rows.
func (matrix Matrix) Rows() [][]int {
	rows := make([][]int, len(matrix))
	for i := range matrix {
		rows[i] = make([]int, len(matrix[i]))
		copy(rows[i], matrix[i])
	}
	return rows
}

// Cols returns the Matrix columns.
func (matrix Matrix) Cols() [][]int {
	cols := make([][]int, len(matrix[0]))
	for i := range matrix[0] {
		cols[i] = make([]int, len(matrix))
		for j := range matrix {
			cols[i][j] = matrix[j][i]
		}
	}
	return cols
}

// Set updates a Matrix cell.
func (matrix Matrix) Set(row int, col int, val int) bool {
	if row < 0 || row >= len(matrix) || col < 0 || col >= len(matrix[0]) {
		return false
	}
	matrix[row][col] = val
	return true
}
