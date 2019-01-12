package isogram

import (
	"strings"
	"unicode"
)

// IsIsogram checks if a given string contains repeating letters.
func IsIsogram(input string) bool {
	word := strings.ToUpper(input)
	for i, r := range word {
		if unicode.IsLetter(r) && strings.ContainsRune(word[i+1:], r) {
			return false
		}
	}
	return true
}
