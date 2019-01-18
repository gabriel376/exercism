package acronym

import (
	"regexp"
	"strings"
	"unicode"
)

// Abbreviate returns the acronym of a given phrase.
func Abbreviate(text string) (out string) {
	version := 4

	switch version {
	case 1: // Benchmark: 500000 | 2824 ns/op | 1152 B/op | 52 allocs/op
		replaced := strings.Replace(text, "-", " ", -1)
		words := strings.Split(replaced, " ")
		acronym := ""
		for _, word := range words {
			if len(word) > 0 {
				acronym += word[:1]
			}
		}
		return strings.ToUpper(acronym)

	case 2: // Benchmark: 1000000 | 1783 ns/op | 1008 B/op | 27 allocs/op
		replaced := strings.Replace(text, "-", " ", -1)
		words := strings.Split(replaced, " ")
		var acronym strings.Builder
		for _, word := range words {
			if len(word) > 0 {
				acronym.WriteString(word[:1])
			}
		}
		return strings.ToUpper(acronym.String())

	case 3: // Benchmark: 20000 | 70661 ns/op | 322512 B/op | 388 allocs/op
		re := regexp.MustCompile("(?:^|-| )([a-zA-Z])")
		var acronym strings.Builder
		for _, match := range re.FindAllStringSubmatch(text, -1) {
			acronym.WriteString(match[1])
		}
		return strings.ToUpper(acronym.String())

	case 4: // Benchmark: 1000000 | 1090 ns/op | 80 B/op | 9 allocs/op
		var acronym strings.Builder
		find := true
		for _, r := range text {
			if find && unicode.IsLetter(r) {
				acronym.WriteRune(unicode.ToUpper(r))
				find = false
			} else if !find && !unicode.IsLetter(r) && r != '\'' {
				find = true
			}
		}
		return acronym.String()
	}

	return ""
}
