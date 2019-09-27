pub fn encode(text: &str) -> String {
    text.to_lowercase()
        .chars()
        .filter_map(flip)
        .enumerate()
        .flat_map(group)
        .collect()
}

pub fn decode(text: &str) -> String {
    text.chars()
        .filter_map(flip)
        .collect()
}

fn flip(chr: char) -> Option<char> {
    match chr {
        '0'...'9' => Some(chr),
        'a'...'z' => Some((b'a' + b'z' - chr as u8) as char),
        _ => None,
    }
}

fn group((index, chr): (usize, char)) -> std::vec::IntoIter<char> {
    let width = 5;
    let mut vec = vec![chr];

    if index > 0 && index % width == 0 {
        vec.insert(0, ' ');
    }

    vec.into_iter()
}
