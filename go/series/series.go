package series

// All returns all series of size n from a given string.
func All(n int, s string) (series []string) {
	for i := 0; i <= len(s)-n; i++ {
		series = append(series, s[i:i+n])
	}
	return
}

// UnsafeFirst returns first serie of size n from a
// given string and panics in case of an invalid size.
func UnsafeFirst(n int, s string) string {
	return s[:n]
}

// First returns first serie of size n from a given string
// and indicates if the execution was successful.
func First(n int, s string) (first string, ok bool) {
	defer func() {
		if r := recover(); r != nil {
			first, ok = "", false
		}
	}()
	return UnsafeFirst(n, s), true
}
