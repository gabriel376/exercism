package armstrong

func digits(num int) (dig []int) {
	for num > 0 {
		dig = append(dig, num%10)
		num /= 10
	}
	return
}

func pow(base int, exp int) int {
	sum := base
	for i := 1; i < exp; i++ {
		sum *= base
	}
	return sum
}

// IsNumber calculates if input is an Armstrong number.
func IsNumber(num int) bool {
	dig := digits(num)
	exp := len(dig)
	sum := 0
	for _, n := range dig {
		sum += pow(n, exp)
	}
	return sum == num
}
