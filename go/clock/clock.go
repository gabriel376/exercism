package clock

import (
    "fmt"
)

// Clock represents a clock object
type Clock struct {
    minutes  int
}

// New creates a new Clock.
func New(hh, mm int) Clock {
    day := 24 * 60
    minutes := (hh*60 + mm) % day
    if (minutes < 0) {
        minutes += day
    }

    return Clock {
        minutes: minutes,
    }
}

// String displays the Clock.
func (clock Clock) String() string {
    return fmt.Sprintf(
        "%02d:%02d",
        clock.minutes / 60,
        clock.minutes % 60);
}

// Add advances the Clock by given minutes.
func (clock Clock) Add(mm int) Clock {
    return New(0, clock.minutes + mm);
}

// Subtract retreats the Clock by given minutes.
func (clock Clock) Subtract(mm int) Clock {
    return New(0, clock.minutes - mm);
}
