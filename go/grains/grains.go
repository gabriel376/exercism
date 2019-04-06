package grains

import (
	"errors"
)

const min int = 1
const max int = 64

// Square returns the number of grains of
// wheat on a chessboard given a square
func Square(num int) (uint64, error) {
	if num < min || num > max {
		return 0, errors.New("Invalid input")
	}
	return 1 << uint64(num-1), nil
}

// Total returns the total number of
// grains of wheat on a chessboard
func Total() uint64 {
	return 1<<uint64(max) - 1
}
