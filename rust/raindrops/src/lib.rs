pub fn raindrops(num: usize) -> String {
    let drops = [(3, "Pling"), (5, "Plang"), (7, "Plong")];

    let sound = drops
        .iter()
        .filter(|(value, _)| num % value == 0)
        .fold(String::new(), |a, (_, sound)| a + sound);

    match sound.len() {
        0 => num.to_string(),
        _ => sound,
    }
}
