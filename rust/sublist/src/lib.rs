#[derive(Debug, PartialEq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

trait Superlist<T> {
    fn superlist_of(&self, other: &[T]) -> bool;
}

impl<T: PartialEq> Superlist<T> for [T] {
    fn superlist_of(&self, other: &[T]) -> bool {
        other.is_empty() || self.windows(other.len()).any(|v| v == other)
    }
}

pub fn sublist<T: PartialEq>(a: &[T], b: &[T]) -> Comparison {
    match (a.superlist_of(b), b.superlist_of(a)) {
        (false, false) => Comparison::Unequal,
        (false, true) => Comparison::Sublist,
        (true, false) => Comparison::Superlist,
        (true, true) => Comparison::Equal,
    }
}
