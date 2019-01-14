// Package gigasecond provides simples time operations.
package gigasecond

import "time"

// AddGigasecond adds one billion seconds to a given date.
func AddGigasecond(t time.Time) time.Time {
	return t.Add(1e9 * time.Second)
}
