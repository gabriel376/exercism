pub fn check(candidate: &str) -> bool {
    let mut set = std::collections::HashSet::new();
    candidate
        .to_lowercase()
        .chars()
        .filter(|c| c.is_alphabetic())
        .all(|c| set.insert(c))
}
