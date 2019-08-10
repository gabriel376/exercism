package clock

import (
    "fmt"
)

// Clock represents a clock object
// with values for hours and minutes.
type Clock struct {
    hours int
    minutes  int
}

// New creates a new Clock.
func New(hours, minutes int) Clock {
    hours += minutes / 60
    hours %= 24
    minutes %= 60

    if (minutes < 0) {
        minutes += 60
        hours--
    }

    if (hours < 0) {
        hours += 24
    }

    return Clock {
        hours: hours,
        minutes: minutes,
    }
}

// String displays the Clock.
func (clock Clock) String() string {
    return fmt.Sprintf("%02d:%02d", clock.hours, clock.minutes);
}

// Add advances the Clock by given minutes.
func (clock Clock) Add(minutes int) Clock {
    return New(clock.hours, clock.minutes + minutes);
}

// Subtract retreats the Clock by given minutes.
func (clock Clock) Subtract(minutes int) Clock {
    return New(clock.hours, clock.minutes - minutes);
}
