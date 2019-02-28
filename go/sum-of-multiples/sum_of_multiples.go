package summultiples

// SumMultiples calculates the sum of all the unique multiples
// of particular numbers up to but not including that number.
func SumMultiples(limit int, divisors ...int) (sum int) {
	for number := 1; number < limit; number++ {
		for _, divisor := range divisors {
			if divisor > 0 && number%divisor == 0 {
				sum += number
				break
			}
		}
	}
	return
}
