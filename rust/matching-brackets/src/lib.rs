pub fn brackets_are_balanced(string: &str) -> bool {
    let delimiters = "()[]{}";
    let mut stack = Vec::new();

    for char in string.chars() {
        match delimiters.find(char) {
            None => (),
            Some(index) => {
                if index % 2 == 0 {
                    stack.push(index+1);

                } else {
                    match stack.pop() {
                        None => return false,
                        Some(value) => {
                            if index != value {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }

    stack.is_empty()
}
