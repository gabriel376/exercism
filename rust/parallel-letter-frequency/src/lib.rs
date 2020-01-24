use std::collections::HashMap;
use std::thread;

pub fn frequency(inputs: &[&str], workers: usize) -> HashMap<char, usize> {
    inputs
        .chunks(if inputs.len() < workers { 1 } else { inputs.len() / workers })
        .map(|input| input.iter().map(|s| s.to_lowercase()).collect::<Vec<_>>())
        .map(|input| {
            thread::spawn(move || {
                input
                    .iter()
                    .flat_map(|s| s.chars().filter(|c| c.is_alphabetic()))
                    .fold(HashMap::new(), |mut map, c| {
                        map.entry(c).and_modify(|n| { *n += 1 }).or_insert(1);
                        map
                    })
            })
        })
        .fold(HashMap::new(), |map, handle| {
            handle.join().unwrap().iter().fold(map, |mut map, (key, val)| {
                map.entry(*key).and_modify(|v| { *v += val }).or_insert(*val);
                map
            })
        })
}
