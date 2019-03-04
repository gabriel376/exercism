pub trait Sqrt<T> {
    fn sqrt(self: &Self) -> Self;
}

pub trait Prime<T> {
    fn is_prime(self: &Self) -> bool;
}

impl Sqrt<u32> for u32 {
    fn sqrt(&self) -> u32 {
        (*self as f32).sqrt() as u32 
    }
}

impl Prime<u32> for u32 {
    fn is_prime(&self) -> bool {
        (2..=self.sqrt()).all(|n| self % n != 0)
    }
}

pub fn nth(n: u32) -> u32 {
    (2..)
        .filter(u32::is_prime)
        .nth(n as usize)
        .unwrap_or(0)
}
