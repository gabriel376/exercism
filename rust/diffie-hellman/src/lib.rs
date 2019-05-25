extern crate rand;

use rand::{thread_rng, Rng};

pub fn private_key(p: u64) -> u64 {
    thread_rng().gen_range(2, p)
}

pub fn public_key(p: u64, g: u64, a: u64) -> u64 {
    mod_exp(g, a, p)
}

pub fn secret(p: u64, b_pub: u64, a: u64) -> u64 {
    mod_exp(b_pub, a, p)
}

// Modular exponentiation: Right-to-left binary method
// See https://en.wikipedia.org/wiki/Modular_exponentiation#Right-to-left_binary_method
fn mod_exp(mut base: u64, mut exp: u64, div: u64) -> u64 {  
    let mut res = 1;
    
    while exp > 0 {
        if exp % 2 == 1 {
            res = (res * base) % div;
        }
        exp >>= 1;
        base = (base * base) % div;
    }
    
    res
}
