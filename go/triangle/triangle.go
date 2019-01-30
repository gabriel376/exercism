// Package triangle provides simple trigonometry functions
package triangle

import (
	"math"
)

// Kind defines a triangle kind
type Kind int

// Declare triangle kinds contants
const (
	NaT = 0
	Equ = 1
	Iso = 2
	Sca = 3
)

// KindFromSides determines the kind of a given triangle
func KindFromSides(a, b, c float64) Kind {
	for _, x := range []float64{a, b, c} {
		if x <= 0 || math.IsNaN(x) || math.IsInf(x, 0) {
			return NaT
		}
	}

	if a > b+c || b > a+c || c > a+b {
		return NaT
	}

	if a == b && b == c {
		return Equ
	}

	if a == b || a == c || b == c {
		return Iso
	}

	return Sca
}
