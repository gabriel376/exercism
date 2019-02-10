package pythagorean

import (
	"math"
)

// Triplet represents a Pythagorean Triangle
type Triplet [3]int

// Range returns a list of all Pythagorean triplets with sides in the
// range min to max inclusive.
func Range(min, max int) (triplets []Triplet) {
	for a := min; a <= max-3; a++ {
		for b := a + 1; b <= max-2; b++ {
			c := int(math.Sqrt(float64(a*a + b*b)))
			if c <= max && a*a+b*b == c*c {
				triplets = append(triplets, Triplet{a, b, c})
			}
		}
	}
	return
}

// Sum returns a list of all Pythagorean triplets where the sum a+b+c
// (the perimeter) is equal to p.
func Sum(p int) (triplets []Triplet) {
	for a := 1; a <= p/3; a++ {
		b := ((p-a)*(p-a) - a*a) / (2 * (p - a))
		c := p - a - b
		if a < b && a*a+b*b == c*c {
			triplets = append(triplets, Triplet{a, b, c})
		}
	}
	return
}
