pub struct PascalsTriangle {
    n: u32,
}

impl PascalsTriangle {
    pub fn new(n: u32) -> Self {
        PascalsTriangle { n }
    }

    pub fn rows(&self) -> Vec<Vec<u32>> {
        (0..self.n).map(Self::row).collect()
    }

    fn row(n: u32) -> Vec<u32> {
        (0..=n).map(|k| Self::binomial_coefficient(n, k)).collect()
    }

    fn binomial_coefficient(n: u32, k: u32) -> u32 {
        Self::factorial(n) / (Self::factorial(k) * Self::factorial(n - k))
    }

    fn factorial(n: u32) -> u32 {
        (1..=n).product()
    }
}
