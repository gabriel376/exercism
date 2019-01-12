package scrabble

import (
	"strings"
)

var scoresByChar = make(map[byte]int)
var scoresByValue = map[int]string{
	1:  "AEIOULNRST",
	2:  "DG",
	3:  "BCMP",
	4:  "FHVWY",
	5:  "K",
	8:  "JX",
	10: "QZ",
}

func init() {
	for score, upper := range scoresByValue {
		lower := strings.ToLower(upper)
		for i := range upper {
			scoresByChar[upper[i]] = score
			scoresByChar[lower[i]] = score
		}
	}
}

// Score calculates the scrabble score
// for a given word. Characters not in
// range a-zA-Z are ignored.
func Score(text string) int {
	total := 0
	for i := range text {
		if score, ok := scoresByChar[text[i]]; ok {
			total += score
		}
	}
	return total
}
