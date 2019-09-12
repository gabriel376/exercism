// Package clock handles basic time operations.
package clock

import (
	"fmt"
)

// Clock represents a clock object.
type Clock int

// New creates a new Clock.
func New(hh, mm int) Clock {
	day := 24 * 60

	minutes := hh*60 + mm
	minutes %= day
	minutes += day
	minutes %= day

	return Clock(minutes)
}

// String displays the Clock.
func (clock Clock) String() string {
	return fmt.Sprintf(
		"%02d:%02d",
		clock/60,
		clock%60)
}

// Add advances the Clock by given minutes.
func (clock Clock) Add(mm int) Clock {
	return New(0, int(clock)+mm)
}

// Subtract retreats the Clock by given minutes.
func (clock Clock) Subtract(mm int) Clock {
	return New(0, int(clock)-mm)
}
