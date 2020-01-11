package romannumerals

import (
	"errors"
	"strings"
)

// Numeral represents a number in different numeric systems.
type Numeral struct {
	arabic int
	roman  string
}

var numerals = [...]Numeral{
	{1000, "M" },
	{900,  "CM"},
	{500,  "D" },
	{400,  "CD"},
	{100,  "C" },
	{90,   "XC"},
	{50,   "L" },
	{40,   "XL"},
	{10,   "X" },
	{9,    "IX"},
	{5,    "V" },
	{4,    "IV"},
	{1,    "I" },
}

// ToRomanNumeral converts an arabic number to roman string.
func ToRomanNumeral(arabic int) (string, error) {
	var roman strings.Builder
	
	if arabic < 1 || arabic > 3000 {
		return "", errors.New("invalid input")
	}

	for _, numeral := range numerals {
		for arabic >= numeral.arabic {
			roman.WriteString(numeral.roman)
			arabic -= numeral.arabic
		}
	}

	return roman.String(), nil
}
