package etl

import (
	"strings"
)

// Transform swaps keys and values of a given map.
func Transform(input map[int][]string) map[string]int {
	output := make(map[string]int)
	for key, values := range input {
		for _, value := range values {
			output[strings.ToLower(value)] = key
		}
	}
	return output
}
