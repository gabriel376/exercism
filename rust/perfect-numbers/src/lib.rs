use std::cmp::Ordering;

#[derive(Debug, PartialEq, Eq)]
pub enum Classification {
    Abundant,
    Perfect,
    Deficient,
}

fn aliquot_sum(num: u64) -> u64 {
    (1..=num / 2).filter(|div| num % div == 0).sum()
}

pub fn classify(num: u64) -> Option<Classification> {
    if num == 0 {
        None
    } else {
        match aliquot_sum(num).cmp(&num) {
            Ordering::Less => Some(Classification::Deficient),
            Ordering::Equal => Some(Classification::Perfect),
            Ordering::Greater => Some(Classification::Abundant),
        }
    }
}
