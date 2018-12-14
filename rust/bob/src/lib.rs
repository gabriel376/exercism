pub fn reply(message: &str) -> &str {
	if has_alphanumeric(&message) && !is_question(&message) {
		return "Fine. Be that way!";

	} else if is_question(&message) && !is_yelling(&message) {
		return "Sure.";

	} else if is_question(&message) && is_yelling(&message) {
		return "Calm down, I know what I'm doing!";

	} else if !is_question(&message) && is_yelling(&message) {
		return "Whoa, chill out!";

	} else {
		return "Whatever.";
	}
}

fn is_question(message: &str) -> bool {
	let chars: Vec<char> = message.trim().chars().collect();
	let len = chars.len();
	message.contains("?") && chars[len-1] == '?'
}

fn is_yelling(message: &str) -> bool {
	message.to_uppercase() == message && has_letter(message)
}

fn has_alphanumeric (message: &str) -> bool {
	let chars: Vec<char> = message.chars().collect();
	for c in chars {
		if c.is_alphanumeric() {
			return false;
		}
	}
	true
}

fn has_letter(message: &str) -> bool {
	let chars: Vec<char> = message.chars().collect();
	for c in chars {
		if c.is_alphabetic() {
			return true;
		}
	}
	false
}
