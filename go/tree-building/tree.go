package tree

import (
	"fmt"
	"sort"
)

// Record represents input tree leaf.
type Record struct {
	ID     int
	Parent int
}

// Node represents output tree leaf.
type Node struct {
	ID       int
	Children []*Node
}

// Build returns an ordered tree of nodes.
func Build(records []Record) (*Node, error) {
	nodes := make(map[int]*Node)
	count := len(records)

	sort.Slice(records, func(i int, j int) bool {
		return records[i].ID < records[j].ID
	})

	for _, record := range records {
		if record.ID < 0 || record.ID >= count {
			return nil, fmt.Errorf("Record ID %d out of bounds", record.ID)
		}

		if (record.ID == 0 && record.Parent != 0) ||
			(record.ID != 0 && record.Parent >= record.ID) {
			return nil, fmt.Errorf("Record ID %d invalid parent", record.ID)
		}

		_, ok := nodes[record.ID]
		if ok {
			return nil, fmt.Errorf("Record ID %d duplicated", record.ID)
		}

		nodes[record.ID] = &Node{
			ID: record.ID,
		}

		if record.ID != 0 {
			parent := nodes[record.Parent]
			parent.Children = append(parent.Children, nodes[record.ID])
		}
	}

	return nodes[0], nil
}
