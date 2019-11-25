pub fn is_valid(code: &str) -> bool {
    code.chars()
        .rev()
        .try_fold((0, 0), calculate)
        .map_or(false, validate)
}

fn calculate((count, total): (usize, u32), c: char) -> Option<(usize, u32)> {
    match c {
        ' ' => Some((count, total)),
        _ => c.to_digit(10)
            .map(|n| if count % 2 == 0 { n } else { 2 * n })
            .map(|n| if n < 10 { n } else { n - 9 })
            .map(|n| (count + 1, total + n)),
    }
}

fn validate((count, total): (usize, u32)) -> bool {
    count > 1 && total % 10 == 0
}
