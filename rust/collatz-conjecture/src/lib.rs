pub fn collatz(mut n: u64) -> Option<u64> {
    let mut steps = 0;
    loop {
        match (n, n % 2) {
            (0, _) => return None,
            (1, _) => return Some(steps),
            (_, 0) => n = n / 2,
            (_, _) => n = n.checked_mul(3)?.checked_add(1)?,
        }
        steps += 1;
    }
}
