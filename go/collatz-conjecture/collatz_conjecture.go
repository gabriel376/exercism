package collatzconjecture

import (
	"errors"
)

// CollatzConjecture calculates how many steps are
// required to solve the Collatz Conjecture problem
func CollatzConjecture(n int) (int, error) {
	if n <= 0 {
		return 0, errors.New("invalid input")
	}

	steps := 0

	for n > 1 {
		steps++
		if n%2 == 0 {
			n /= 2
		} else {
			n = 3*n + 1
		}
	}

	return steps, nil
}
