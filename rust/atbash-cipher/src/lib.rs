pub fn encode(text: &str) -> String {
    text.to_lowercase().chars()
        .filter_map(flip)
        .collect::<Vec<char>>()
        .chunks(5)
        .collect::<Vec<_>>()
        .join(&' ')
        .into_iter()
        .collect()
}

pub fn decode(text: &str) -> String {
    text.chars()
        .filter_map(flip)
        .collect()
}

fn flip(c: char) -> Option<char> {
    match c {
        '0'...'9' => Some(c),
        'a'...'z' => Some((b'a' + b'z' - c as u8) as char),
        _ => None,
    }
}
