use std::collections::HashMap;
use regex::Regex;

/// Count occurrences of words.
pub fn word_count(words: &str) -> HashMap<String, u32> {
    Regex::new(r"[a-zA-Z0-9]+('[a-z])?").expect("invalid regex")
        .find_iter(words)
        .map(|w| w.as_str().to_lowercase())
        .fold(HashMap::new(), |mut m, w| {
            *m.entry(w).or_insert(0) += 1;
            m
        })
}
