package hamming

import (
	"errors"
)

// Distance calculates the Hamming distance between two DNA strands.
// Both DNA strands must have the same length.
func Distance(left, right string) (int, error) {
	if len(left) != len(right) {
		return -1, errors.New("left and right strands must be of equal length")
	}
	
	dist := 0
	for idx := range left {
		if left[idx] != right[idx] {
			dist++
		}
	}
	return dist, nil
}
