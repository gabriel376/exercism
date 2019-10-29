pub fn spiral_matrix(size: usize) -> Vec<Vec<u32>> {
    (1..=size)
        .rev()
        .flat_map(|n| vec!(n, n).into_iter())
        .skip(1)
        .zip([(0,1),(1,0),(0,-1),(-1,0)].iter().cycle())
        .flat_map(|(n, (ox, oy))| vec!((*ox, *oy)).into_iter().cycle().take(n))
        .fold((vec![vec![0u32; size]; size], 0, -1, 0), |(mut array, x, y, n), (ox, oy)| {
            array[(x + ox) as usize][(y + oy) as usize] = n + 1;
            (array, x + ox, y + oy, n + 1)
        })
        .0.iter()
        .map(|row| row.to_vec())
        .collect()
}
