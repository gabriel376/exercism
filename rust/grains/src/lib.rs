const MIN: u32 = 1;
const MAX: u32 = 64;

pub fn square(s: u32) -> u64 {
    match s {
        MIN...MAX => (2 as u64).pow(s - 1),
        _ => panic!("Square must be between {} and {}", MIN, MAX),
    }
}

pub fn total() -> u64 {
    (MIN..MAX + 1).map(square).sum()
}
