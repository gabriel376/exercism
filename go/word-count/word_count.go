package wordcount

import (
	"regexp"
	"strings"
)

// Frequency represents a histogram of words.
type Frequency map[string]int

// WordCount returns the frequency of each word
// in a phrase.
func WordCount(phrase string) Frequency {
	freq := make(Frequency)
	re := regexp.MustCompile(`[a-zA-Z0-9]+(\'[a-z])?`)
	lower := strings.ToLower(phrase)

	for _, word := range re.FindAllString(lower, -1) {
		freq[word]++
	}

	return freq
}
