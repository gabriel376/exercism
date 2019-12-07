package scrabble

import (
	"unicode"
)

// Score calculates the scrabble score for a given word.
// Characters not in range a-zA-Z are ignored.
func Score(text string) (total int) {
	for _, r := range text {
		switch unicode.ToLower(r) {
		case 'a', 'e', 'i', 'o', 'u', 'l', 'n', 'r', 's', 't':
			total++
		case 'd', 'g':
			total += 2
		case 'b', 'c', 'm', 'p':
			total += 3
		case 'f', 'h', 'v', 'w', 'y':
			total += 4
		case 'k':
			total += 5
		case 'j', 'x':
			total += 8
		case 'q', 'z':
			total += 10
		}
	}
	return total
}
