pub fn reverse(input: &str) -> String {
    let chars: Vec<char> = input.chars().collect();
    let len = chars.len();
    let mut reverse = String::from("");
    for i in 0..len {
        let c = chars[len-i-1];
        reverse.push(c);
    }
    reverse
}
