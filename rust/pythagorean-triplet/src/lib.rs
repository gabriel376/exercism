use std::collections::HashSet;
use rayon::iter::{IntoParallelIterator, ParallelIterator};

pub fn find(sum: u32) -> HashSet<[u32; 3]> {
    (1..sum / 3)
        .into_par_iter()
        .filter_map(|a| {
            let b = ((sum - a).pow(2) - a.pow(2)) / (2 * (sum - a));
            let c = sum - a - b;

            match a < b && a.pow(2) + b.pow(2) == c.pow(2) {
                true => Some([a, b, c]),
                false => None,
            }
        })
        .collect::<HashSet<[u32; 3]>>()
}
