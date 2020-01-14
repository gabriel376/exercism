package tournament

// Result represents a team result.
type Result string

// Invert returns the opposite result.
func (r *Result) Invert() Result {
	switch *r {
	case "win":
		return Result("loss")
	case "loss":
		return Result("win")
	default:
		return Result(*r)
	}
}
