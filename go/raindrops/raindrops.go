package raindrops

import (
	"strconv"
	"strings"
)

type Drop struct {
	value int
	sound string
}

// Convert transforms a number into a raindrop sound
func Convert(num int) string {
	var DROPS = []Drop{
		{value: 3, sound: "Pling"},
		{value: 5, sound: "Plang"},
		{value: 7, sound: "Plong"},
	}

	var drops strings.Builder
	for i := 0; i < len(DROPS); i++ {
		if num%DROPS[i].value == 0 {
			drops.WriteString(DROPS[i].sound)
		}
	}

	if drops.Len() == 0 {
		return strconv.Itoa(num)
	}
	return drops.String()
}
