package robotname

import (
	"errors"
	"math/rand"
	"time"
)

// Robot represents a robot.
type Robot struct {
	name string
}

type nameConfigPart struct {
	start rune
	size  int
}

var max int
var index int
var numbers []int
var config = []nameConfigPart{
	{'A', 26},
	{'A', 26},
	{'0', 10},
	{'0', 10},
	{'0', 10},
}

func init() {
	rand.Seed(time.Now().UnixNano())

	max = 1
	for _, elem := range config {
		max *= elem.size
	}

	index = 0
	numbers = rand.Perm(max)
}

// Reset clears robot name.
func (robot *Robot) Reset() {
	robot.name = ""
}

// Name returns robot name.
func (robot *Robot) Name() (string, error) {
	if index >= max {
		return "", errors.New("names exhausted")
	}

	if robot.name != "" {
		return robot.name, nil
	}

	num := numbers[index]
	runes := []rune{}
	prod := 1

	for _, elem := range config {
		r := rune(num/prod%elem.size) + elem.start
		runes = append(runes, r)
		prod *= elem.size
	}

	index++
	robot.name = string(runes)

	return robot.name, nil
}
