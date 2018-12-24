// Package listops provides standard list operations
package listops

// IntList is a list of integers
type IntList []int

type binFunc func(x, y int) int
type predFunc func(n int) bool
type unaryFunc func(x int) int

// Foldl applies a function to all elements to produce
// a single output value.
func (list IntList) Foldl(fn binFunc, initial int) int {
	result := initial
	for _, value := range list {
		result = fn(result, value)
	}
	return result
}

// Foldr applies a function in reverse order to all
// elements to produce a single output value.
func (list IntList) Foldr(fn binFunc, initial int) int {
	length := list.Length()
	result := initial
	for index := range list {
		result = fn(list[length-index-1], result)
	}
	return result
}

// Filter produces a new array with all elements that
// pass the test function.
func (list IntList) Filter(fn predFunc) IntList {
	result := make(IntList, len(list))
	found := 0
	for _, value := range list {
		if fn(value) {
			result[found] = value
			found++
		}
	}
	return result[0:found]
}

// Length returns the number of elements in list.
func (list IntList) Length() int {
	return len(list)
}

// Map produces a new array with the outputs of all
// elements passed to the transformation function.
func (list IntList) Map(fn unaryFunc) IntList {
	result := make(IntList, list.Length())
	for index, value := range list {
		result[index] = fn(value)
	}
	return result
}

// Reverse produces a new array in inverse order.
func (list IntList) Reverse() IntList {
	length := list.Length()
	result := make(IntList, length)
	for index, value := range list {
		result[length-index-1] = value
	}
	return result
}

// Append joins two lists into one list.
func (list IntList) Append(values IntList) IntList {
	result := list
	result = append(result, values...)
	return result
}

// Concat joins multiple lists into one list.
func (list IntList) Concat(lists []IntList) IntList {
	result := list
	for _, values := range lists {
		result = append(result, values...)
	}
	return result
}
