use std::collections::HashSet;

pub fn anagrams_for<'a>(word: &str, candidates: &[&'a str]) -> HashSet<&'a str> {
    let lower_word = word.to_lowercase();
    let sorted_word = sort_chars(&lower_word);

    let is_anagram = |candidate: &&&str| {
        if candidate.len() == word.len() {
            let lower_candidate = candidate.to_lowercase();
            lower_candidate != lower_word && sort_chars(&lower_candidate) == sorted_word
        } else {
            false
        }
    };

    candidates.iter()
        .filter(is_anagram)
        .cloned()
        .collect()
}

fn sort_chars(word: &str) -> Vec<char> {
    let mut chars: Vec<char> = word.chars().collect();
    chars.sort();
    chars
}
