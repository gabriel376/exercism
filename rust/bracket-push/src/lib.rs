pub fn brackets_are_balanced(string: &str) -> bool {
    let delimiters = "()[]{}";
    let mut stack = Vec::new();

    for char in string.chars() {
        match delimiters.find(char) {
            None => continue,
            Some(index) => {
                if index % 2 == 0 {
                    stack.push(index+1);
                } else if index != stack.pop().unwrap_or(0) {
                    return false;
                }
            }
        }
    }

    stack.is_empty()
}
