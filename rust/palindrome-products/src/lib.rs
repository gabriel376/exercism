#[derive(Debug, PartialEq, Eq)]
pub struct Palindrome {
    factors: Vec<(u64, u64)>,
}

impl Palindrome {
    pub fn generate(min: u64, max: u64, num: u64) -> Option<Palindrome> {
        if !Self::is_valid(num) {
            return None;
        }

        let factors = (min..max)
            .filter_map(|a| Self::factor(a, num, max))
            .collect::<Vec<_>>();

        if factors.is_empty() {
            None
        } else {
            Some(Self { factors })
        }
    }

    fn is_valid(num: u64) -> bool {
        let mut temp = num;
        let mut reversed = 0;

        while temp > 0 {
            reversed *= 10;
            reversed += temp % 10;
            temp /= 10;
        }

        num == reversed
    }

    fn factor(a: u64, num: u64, max: u64) -> Option<(u64, u64)> {
        let b = num / a;
        if num % a == 0 && b >= a && b <= max {
            Some((a, b))
        } else {
            None
        }
    }

    pub fn new(a: u64, b: u64) -> Palindrome {
        Palindrome {
            factors: vec![(a, b)],
        }
    }

    pub fn insert(&mut self, a: u64, b: u64) {
        self.factors.push((a, b));
    }
}

pub fn palindrome_products(min: u64, max: u64) -> Option<(Palindrome, Palindrome)> {
    if min > max {
        return None;
    }

    let smallest_product = min.pow(2);
    let largest_product = max.pow(2);
    let diff_product = largest_product - smallest_product;

    let mut result:(Option<Palindrome>, Option<Palindrome>) = (None, None);

    for num in 0..=diff_product {
        let small_product = smallest_product + num;
        let large_product = largest_product - num;

        match result {
            (None, _) => {
                result.0 = Palindrome::generate(min, max, small_product);
            },
            (_, None) => {
                result.1 = Palindrome::generate(min, max, large_product);
            },
            (Some(a), Some(b)) => {
                return Some((a, b));
            },
        }
    }

    None
}
