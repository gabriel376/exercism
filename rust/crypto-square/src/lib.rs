pub fn encrypt(input: &str) -> String {
    let chars = input
        .to_lowercase()
        .chars()
        .filter(|c| c.is_ascii_alphanumeric())
        .collect::<Vec<char>>();

    let len = chars.len() as f64;
    let rows = len.sqrt().ceil() as usize;
    let cols = len.sqrt().floor() as usize;

    let get_char = |r, c| chars.get(c*rows + r).unwrap_or(&' ');
    let get_line = |r| (0..cols).map(|c| get_char(r, c)).collect();

    (0..rows).map(get_line).collect::<Vec<String>>().join(" ")
}
