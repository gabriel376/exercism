package darts

import "math"

// Circle represents a target circle in Darts game.
type Circle struct {
	radius float64
	score  int
}

var circles = [...]Circle{
	{radius: 1.0,  score: 10},
	{radius: 5.0,  score: 5},
	{radius: 10.0, score: 1},
}

// Score returns the earned points in Darts game.
func Score(x, y float64) int {
	dist := math.Sqrt(x*x + y*y)
	for _, circle := range circles {
		if dist <= circle.radius {
			return circle.score
		}
	}
	return 0
}
