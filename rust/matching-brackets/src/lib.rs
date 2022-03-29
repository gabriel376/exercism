pub fn brackets_are_balanced(string: &str) -> bool {
    let delimiters = "()[]{}";
    let mut stack = Vec::new();

    for char in string.chars() {
        match delimiters.find(char) {
            None => (),
            Some(index) => match index % 2 {
                0 => stack.push(index + 1),
                _ => match stack.pop() {
                    None => return false,
                    Some(value) => match index == value {
                        true => (),
                        false => return false,
                    },
                },
            },
        }
    }

    stack.is_empty()
}
