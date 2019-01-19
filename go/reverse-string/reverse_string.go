package reverse

import (
	"strings"
)

// String reverses the runes of a given string
func String(text string) string {
	var output strings.Builder
	runes := []rune(text)

	for i := len(runes) - 1; i >= 0; i-- {
		output.WriteRune(runes[i])
	}

	return output.String()
}
