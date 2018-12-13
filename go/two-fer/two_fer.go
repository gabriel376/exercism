package twofer

import (
	"fmt"
)

// ShareWith returns a two-fer message.
func ShareWith(name string) string {
	msg := "One for %s, one for me."
	if name == "" {
		name = "you"
	}
	return fmt.Sprintf(msg, name)
}
