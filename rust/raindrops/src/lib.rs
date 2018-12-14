pub fn raindrops(n: usize) -> String {
	let three_str = String::from("Pling");
	let five_str = String::from("Plang");
	let seven_str = String::from("Plong");
	let mut found = false;
	let mut final_str = String::from("");

	if n % 3 == 0 {
		final_str.push_str(&three_str);
		found = true;
	}

	if n % 5 == 0 {
		final_str.push_str(&five_str);
		found = true;
	}

	if n % 7 == 0 {
		final_str.push_str(&seven_str);
		found = true;
	}

	if !found {
		final_str = n.to_string();
	}

	final_str
}
