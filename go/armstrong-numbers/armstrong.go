package armstrong

func pow(base int, exp int) int {
	sum := base
	for i := 1; i < exp; i++ {
		sum *= base
	}
	return sum
}

func digitsLength(num int) (length int) {
    for num > 0 {
        length++
        num /= 10
    }
    return
}

func toArmstrong(num int) (sum int) {
    exp := digitsLength(num)
    for num > 0 {
        sum += pow(num % 10, exp)
        num /= 10
    }
    return
}

// IsNumber calculates if input is an Armstrong number.
func IsNumber(num int) bool {
    return toArmstrong(num) == num
}
