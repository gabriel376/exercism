pub fn is_leap_year(year: u64) -> bool {
    let div_by = |x| year % x == 0;
    match (div_by(4), div_by(100), div_by(400)) {
        (true, false, _) => true,
        (_, _, true) => true,
        (_, _, _) => false,
    }
}
