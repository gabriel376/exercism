pub fn nth(n: u32) -> u32 {
    (2..<u32>::max_value())
        .filter(|a| (2..a - 1).all(|b| a % b != 0))
        .nth(n as usize)
        .unwrap()
}
