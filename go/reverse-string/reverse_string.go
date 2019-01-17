package reverse

import (
	"strings"
	"unicode/utf8"
)

// String reverses the runes of a given string
func String(text string) string {
	var rev strings.Builder
	size := len(text)
	for size > 0 {
		r, i := utf8.DecodeLastRuneInString(text)
		rev.WriteRune(r)
		size = size - i
		text = text[:size]
	}
	return rev.String()
}
