pub fn is_valid(code: &str) -> bool {
    if code.chars().any(|c| c != ' ' && !c.is_ascii_digit()) {
        return false;
    }

    let numbers: Vec<u32> = code
        .chars()
        .rev()
        .filter_map(|c| c.to_digit(10))
        .enumerate()
        .map(|(i, n)| if i % 2 == 0 { n } else { 2 * n })
        .map(|n| if n < 10 { n } else { n - 9 })
        .collect();

    numbers.len() > 1 && numbers.iter().sum::<u32>() % 10 == 0
}
