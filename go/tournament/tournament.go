package tournament

import (
	"bufio"
	"fmt"
	"io"
	"strings"
)

// Tally returns a tally table
func Tally(reader io.Reader, writer io.Writer) error {
	scanner := bufio.NewScanner(reader)
	var teams Teams

	for scanner.Scan() {
		line := scanner.Text()
		if line == "" || strings.HasPrefix(line, "#") {
			continue
		}

		parts := strings.Split(line, ";")
		if len(parts) != 3 {
			return fmt.Errorf("invalid data")
		}

		homeTeamName := parts[0]
		homeTeamResult := Result(parts[2])
		err := teams.Add(homeTeamName, homeTeamResult)
		if err != nil {
			return err
		}

		visitorTeamName := parts[1]
		visitorTeamResult := homeTeamResult.Invert()
		err = teams.Add(visitorTeamName, visitorTeamResult)
		if err != nil {
			return err
		}
	}

	teams.Sort()

	io.WriteString(writer, fmt.Sprintf("%-30s | %2s | %2s | %2s | %2s | %2s\n",
		"Team", "MP", "W", "D", "L", "P"))
	for _, team := range teams {
		io.WriteString(writer, team.String())
	}

	return nil
}
