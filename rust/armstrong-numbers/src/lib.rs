pub fn is_armstrong_number(num: u32) -> bool {
    let num_str = num.to_string();
    let num_len = num_str.len() as u32;
    let sum: u32 = num_str.chars()
        .map(|n| n.to_digit(10).unwrap())
        .map(|n| n.pow(num_len))
        .sum();
    sum == num
}
