use std::collections::HashSet;
use std::iter::FromIterator;

pub fn find(sum: u32) -> HashSet<[u32; 3]> {
    HashSet::from_iter(
        (1..sum - 3)
            .flat_map(|a| (a + 1..sum - a).map(move |b| (a, b, sum - a - b)))
            .filter(|(a, b, c)| a.pow(2) + b.pow(2) == c.pow(2))
            .map(|(a, b, c)| [a, b, c]),
    )
}
