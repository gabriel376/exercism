package accumulate

// Accumulate applies a function to all array elements
func Accumulate(input []string, operation func(string) string) []string {
	accumulated := make([]string, len(input))
	for index, value := range input {
		accumulated[index] = operation(value)
	}
	return accumulated
}
