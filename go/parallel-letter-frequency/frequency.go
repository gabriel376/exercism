package letter

// FreqMap records the frequency of each rune in a given text.
type FreqMap map[rune]int

// Frequency counts the frequency of each rune in a given text
// and returns this data as a FreqMap.
func Frequency(s string) FreqMap {
	m := FreqMap{}
	for _, r := range s {
		m[r]++
	}
	return m
}

// ConcurrentFrequency runs function FreqMap in concurrent mode.
func ConcurrentFrequency(inputs []string) FreqMap {
	result := FreqMap{}
	channel := make(chan FreqMap)

	for _, s := range inputs {
		go func(s string) {
			channel <- Frequency(s)
		}(s)
	}

	for range inputs {
		for key, val := range <-channel {
			result[key] += val
		}
	}

	return result
}
