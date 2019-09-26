use std::ops::Add;

pub struct Triangle<T> {
    low: T,
    mid: T,
    high: T,
}

impl<T: PartialEq + PartialOrd + Copy + Add<T, Output = T>> Triangle<T> {
    pub fn build(mut sides: [T; 3]) -> Option<Triangle<T>> {
        sides.sort_by(|a, b| a.partial_cmp(b).unwrap());
        let [low, mid, high] = sides;

        if high >= low + mid {
            return None;
        } else {
            Some(Triangle { low, mid, high })
        }
    }

    pub fn is_equilateral(&self) -> bool {
        self.low == self.high
    }

    pub fn is_isosceles(&self) -> bool {
        self.low == self.mid || self.mid == self.high
    }

    pub fn is_scalene(&self) -> bool {
        self.low != self.mid && self.mid != self.high
    }
}
