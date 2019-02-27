package luhn

import (
	"unicode"
)

// Valid calculates if a given number is valid
// per the Luhn formula.
func Valid(input string) bool {
	sum := 0
	digits := 0

	for _, char := range input {
		if unicode.IsDigit(char) {
			digit := int(char - '0')
			if digits%2 == len(input)%2 {
				digit *= 2
				if digit > 9 {
					digit -= 9
				}
			}
			sum += digit
			digits++

		} else if !unicode.IsSpace(char) {
			return false
		}
	}

	return digits > 1 && sum%10 == 0
}
