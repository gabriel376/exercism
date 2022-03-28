package robotname

import (
	"errors"
	"math/rand"
	"time"
)

var (
	names []string
)

func product(xs ...[]string) []string {
	if len(xs) == 1 {
		return xs[0]
	}

	prod := make([]string, 0, len(xs))
	for _, v1 := range xs[0] {
		for _, v2 := range xs[1] {
			prod = append(prod, v1+v2)
		}
	}

	args := make([][]string, 0, len(xs)-1)
	args = append(args, prod)
	args = append(args, xs[2:]...)

	return product(args...)
}

func init() {
	letters := make([]string, 0, 26)
	for c := 'A'; c <= 'Z'; c++ {
		letters = append(letters, string(c))
	}

	digits := make([]string, 0, 10)
	for c := '0'; c <= '9'; c++ {
		digits = append(digits, string(c))
	}

	names = product(letters, letters, digits, digits, digits)

	rand.Seed(time.Now().UnixNano())
	rand.Shuffle(len(names), func(i, j int) {
		names[i], names[j] = names[j], names[i]
	})
}

// Robot represents a robot.
type Robot struct {
	name string
}

// Reset clears the robot name.
func (robot *Robot) Reset() {
	robot.name = ""
}

// Name returns the robot name.
func (robot *Robot) Name() (string, error) {
	if robot.name != "" {
		return robot.name, nil
	}

	if len(names) == 0 {
		return "", errors.New("No more names available")
	}

	robot.name = names[0]
	names = names[1:]

	return robot.name, nil
}
