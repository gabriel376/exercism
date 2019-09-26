package prime

import "math"

var primes = []int{2}

// Nth returns the nth prime.
func Nth(nth int) (int, bool) {
	count := len(primes)

	for num := primes[count-1] + 1; nth > 0; num++ {
		if count >= nth {
			return primes[nth-1], true
		}
		if isPrime(num) {
			primes = append(primes, num)
			count++
		}
	}

	return 0, false
}

// isPrime checks is a given number is prime.
func isPrime(number int) bool {
	limit := int(math.Sqrt(float64(number)))

	for n := 2; n <= limit; n++ {
		if number%n == 0 {
			return false
		}
	}

	return true
}
