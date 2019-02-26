pub fn find_saddle_points(rows: &[Vec<u64>]) -> Vec<(usize, usize)> {
    (0..rows.len())
        .flat_map(|x| (0..rows[x].len()).map(move |y| (x, y)))
        .filter(|(x, y)| rows[*x].iter().all(|val| rows[*x][*y] >= *val))
        .filter(|(x, y)| rows.iter().all(|row| rows[*x][*y] <= row[*y]))
        .collect()
}
