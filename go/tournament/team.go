package tournament

import (
	"fmt"
)

// Team represents a team.
type Team struct {
	Wins   int
	Draws  int
	Losses int
	Name   string
}

// Matches return how many matches the team has played.
func (t *Team) Matches() int {
	return t.Wins + t.Draws + t.Losses
}

// Points returns how many points the team has earned.
func (t *Team) Points() int {
	return 3*t.Wins + t.Draws
}

// String returns a tally row.
func (t *Team) String() string {
	return fmt.Sprintf("%-30s | %2d | %2d | %2d | %2d | %2d\n",
		t.Name,
		t.Matches(),
		t.Wins,
		t.Draws,
		t.Losses,
		t.Points())
}
