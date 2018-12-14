pub fn verse(n: i32) -> String {
	println!("{}",n);
	let current = get_bottle_msg(n);
	let action = get_action_msg(n);
	let next = get_bottle_msg(n-1);

	String::from(
		format!(
			"{} of beer on the wall, {} of beer.\n{}, {} of beer on the wall.\n",
			current,
			current.to_lowercase(),
			action,
			next.to_lowercase()
		)
	)
}

fn get_bottle_msg(i: i32) -> String {
	let message;

	if i < 0 {
		message = String::from("99 bottles");
	
	} else if i == 0 {
		message = String::from("No more bottles");
	
	} else if i == 1 {
		message = String::from("1 bottle");
	
	} else {
		message = String::from(format!("{} bottles", i));
	}

	message
}

fn get_action_msg(i: i32) -> String {
	let message;

	if i == 0 {
		message = String::from("Go to the store and buy some more");

	} else if i == 1 {
		message = String::from("Take it down and pass it around");

	} else {
		message = String::from("Take one down and pass it around");
	}

	message
}

pub fn sing(start: i32, end: i32) -> String {
	let mut song = String::from("");

	for i in (end-1..start).rev() {
		song.push_str(&verse(i+1));
		song.push_str("\n");
	}

	song.pop();
	song
}
