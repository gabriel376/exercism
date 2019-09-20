use std::collections::HashSet;

pub fn primes_up_to(num: u64) -> Vec<u64> {
    let mut sieve = HashSet::new();
    (2..=num).filter(|n| {
        sieve.extend((n+n..=num).step_by(*n as usize));
        !sieve.contains(n)
    }).collect()
}
