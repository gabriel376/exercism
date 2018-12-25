pub fn factors(mut n: u64) -> Vec<u64> {
    let mut vec = Vec::new();
    let mut div = 2;
    while n > 1 {
        if n % div == 0 {
            vec.push(div);
            n /= div;
            continue;
        }
        div += 1;
    }
    vec
}
