package strain

// Ints is a list of int
type Ints []int

// Lists is list of lists of int
type Lists [][]int

// Strings is a list of string
type Strings []string

// Keep creates a collection of items that match a given predicate.
func (ints Ints) Keep(fn func(int) bool) Ints {
	if ints == nil {
		return nil
	}

	var kept Ints
	for _, i := range ints {
		if fn(i) {
			kept = append(kept, i)
		}
	}
	return kept
}

// Discard creates a collection of items that don't match a given predicate.
func (ints Ints) Discard(fn func(int) bool) Ints {
	return ints.Keep(func(i int) bool {
		return !fn(i)
	})
}

// Keep creates a collection of items that match a given predicate.
func (lists Lists) Keep(fn func([]int) bool) Lists {
	if lists == nil {
		return nil
	}

	var kept Lists
	for _, l := range lists {
		if fn(l) {
			kept = append(kept, l)
		}
	}
	return kept
}

// Keep creates a collection of items that match a given predicate.
func (strings Strings) Keep(fn func(string) bool) Strings {
	if strings == nil {
		return nil
	}

	var kept Strings
	for _, s := range strings {
		if fn(s) {
			kept = append(kept, s)
		}
	}
	return kept
}
