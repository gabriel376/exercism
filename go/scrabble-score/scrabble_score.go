package scrabble

import (
	"strings"
)

var scoresByChar = make(map[byte]int)

func init() {
	scoresByValue := make(map[int]string)
	scoresByValue[1] = "AEIOULNRST"
	scoresByValue[2] = "DG"
	scoresByValue[3] = "BCMP"
	scoresByValue[4] = "FHVWY"
	scoresByValue[5] = "K"
	scoresByValue[8] = "JX"
	scoresByValue[10] = "QZ"

	for score, upper := range scoresByValue {
		lower := strings.ToLower(upper)
		for i, _ := range upper {
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

	for i, _ := range text {
		score, ok := scoresByChar[text[i]]
		if ok {
			total += score
		}
	}

	return total
}
