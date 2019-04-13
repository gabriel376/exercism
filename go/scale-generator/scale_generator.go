package scale

import "strings"

var sharp = []string{"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"}
var flat = []string{"A", "Bb", "B", "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab"}
var steps = map[rune]int{'m': 1, 'M': 2, 'A': 3}

// Scale generates a musical scale starting with a given
// tonic and following the specified interval pattern.
func Scale(tonic string, interval string) []string {
	scale := make([]string, 12)

	switch tonic {
	case "g", "Db", "d", "F", "bb", "Eb":
		copy(scale, flat)
	default:
		copy(scale, sharp)
	}

	if tonic != scale[0] {
		for i, note := range scale {
			if strings.EqualFold(tonic, note) {
				scale = append(scale[i:], scale[:i]...)
				break
			}
		}
	}

	for i, step := range interval {
		scale = append(scale[0:i+1], scale[i+steps[step]:]...)
	}

	return scale
}
