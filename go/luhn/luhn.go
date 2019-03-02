package luhn

import (
	"unicode"
)

// Valid calculates if a given number
// is valid per the Luhn formula.
func Valid(input string) bool {
	sum := 0
	count := 0

	for _, char := range input {
		if unicode.IsSpace(char) {
			continue
		}

		if !unicode.IsDigit(char) {
			return false
		}

		digit := int(char - '0')
		if count%2 == len(input)%2 {
			digit *= 2
			if digit > 9 {
				digit -= 9
			}
		}
		sum += digit
		count++
	}

	return count > 1 && sum%10 == 0
}
