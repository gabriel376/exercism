package diffsquares

// SquareOfSum calculates the square
// of the sum of the first n integers.
func SquareOfSum(n int) int {
	sum := n * (n + 1) / 2
	return sum * sum
}

// SumOfSquares calculates the sum
// of the square of the first n integers.
func SumOfSquares(n int) int {
	return n * (n + 1) * ((2 * n) + 1) / 6
}

// Difference calculates the difference between
// the SquareOfSum and SumOfSquares.
func Difference(n int) int {
	return SquareOfSum(n) - SumOfSquares(n)
}
