package raindrops

import (
	"strconv"
	"strings"
)

// Convert transforms a number into a raindrop sound
func Convert(num int) string {
	var drops strings.Builder

	if num%3 == 0 {
		drops.WriteString("Pling")
	}
	if num%5 == 0 {
		drops.WriteString("Plang")
	}
	if num%7 == 0 {
		drops.WriteString("Plong")
	}

	if drops.Len() == 0 {
		return strconv.Itoa(num)
	}
	return drops.String()
}
