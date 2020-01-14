package tournament

import (
	"fmt"
	"sort"
)

// Teams represents a table of teams.
type Teams []*Team

// Find searches for a team in table.
func (t *Teams) Find(name string) (*Team, bool) {
	for _, team := range *t {
		if team.Name == name {
			return team, true
		}
	}
	return nil, false
}

// Add inserts a team to the table.
func (t *Teams) Add(name string, result Result) error {
	team, found := t.Find(name)
	if !found {
		team = &Team{0, 0, 0, name}
		*t = append(*t, team)
	}

	switch result {
	case "win":
		team.Wins++
	case "draw":
		team.Draws++
	case "loss":
		team.Losses++
	default:
		return fmt.Errorf("invalid result")
	}

	return nil
}

// Sort sorts the table.
func (t *Teams) Sort() {
	sort.Slice(*t, func(a, b int) bool {
		if (*t)[a].Points() == (*t)[b].Points() {
			return (*t)[a].Name < (*t)[b].Name
		}
		return (*t)[a].Points() > (*t)[b].Points()
	})
}
