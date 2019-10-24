package sieve

// Sieve calculates all prime numbers up to given
// input using Sieve of Eratosthenes algorithm.
func Sieve(number int) (primes []int) {
	sieve := make([]bool, number+1)

	for i := 2; i <= number; i++ {
		if !sieve[i] {
			primes = append(primes, i)
			for j := i + i; j <= number; j += i {
				sieve[j] = true
			}
		}
	}

	return primes
}
