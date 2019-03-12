package prime

import "math"

// Nth returns the nth prime.
func Nth(number int) (int, bool) {
	count := 0

	for n := 2; number > 0; n++ {
		if isPrime(n) {
			count++
		}
		if number == count {
			return n, true
		}
	}

	return 0, false
}

// isPrime checks if a given number is prime.
func isPrime(number int) bool {
	limit := int(math.Sqrt(float64(number)))

	for n := 2; n <= limit; n++ {
		if number%n == 0 {
			return false
		}
	}

	return true
}
