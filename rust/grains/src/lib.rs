const MIN: u32 = 1;
const MAX: u32 = 64;

pub fn square(num: u32) -> u64 {
    match num {
        MIN...MAX => 2u64.pow(num - 1),
        _ => panic!("Square must be between {} and {}", MIN, MAX),
    }
}

pub fn total() -> u64 {
    u64::max_value()
}
