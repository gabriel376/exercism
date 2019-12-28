package twelve

import (
	"fmt"
	"strings"
)

var (
    start = "On the %s day of Christmas my true love gave to me: "
    gifts = []string{
        "a Partridge in a Pear Tree.",
        "two Turtle Doves, and ",
        "three French Hens, ",
        "four Calling Birds, ",
        "five Gold Rings, ",
        "six Geese-a-Laying, ",
        "seven Swans-a-Swimming, ",
        "eight Maids-a-Milking, ",
        "nine Ladies Dancing, ",
        "ten Lords-a-Leaping, ",
        "eleven Pipers Piping, ",
        "twelve Drummers Drumming, ",
    }
    ordinals = []string{
        "first",
        "second",
        "third",
        "fourth",
        "fifth",
        "sixth",
        "seventh",
        "eighth",
        "ninth",
        "tenth",
        "eleventh",
        "twelfth",
    }
)

// Verse returns a single verse of 'The Twelve Days of Christmas' song.
func Verse(row int) string {
	var result strings.Builder

	result.WriteString(fmt.Sprintf(start, ordinals[row-1]))

	for i := row - 1; i >= 0; i-- {
		result.WriteString(gifts[i])
	}

	return result.String()
}

// Song returns the full lyrics of 'The Twelve Days of Christmas' song.
func Song() string {
	verses := make([]string, len(gifts))

	for index := range verses {
		verses[index] = Verse(index + 1)
	}

	return strings.Join(verses, "\n")
}
