package secret

var moves = []string{
	"wink",
	"double blink",
	"close your eyes",
	"jump",
}

// isBitSet checks if a bit is set in a given number.
func isBitSet(num uint, bit uint) bool {
	return (num & (1 << bit)) > 0
}

// Handshake calculates the movements of a
// Secret Handshake according to a given code.
func Handshake(code uint) (handshake []string) {
	reverse := isBitSet(code, uint(len(moves)))

	for index, move := range moves {
		if !isBitSet(code, uint(index)) {
			continue
		}

		if reverse {
			handshake = append([]string{move}, handshake...)
		} else {
			handshake = append(handshake, move)
		}
	}

	return handshake
}
