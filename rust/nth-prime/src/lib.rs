pub fn nth(n: u32) -> Option<u32> {
	let mut count = 0;

	if n == 0 {
		return None;
	}

	for i in 2..<u32>::max_value() {
		if is_prime(i) {
			count = count + 1;
			if count == n {
				return Some(i);
			}
		}
	}
	None
}

fn is_prime(n: u32) -> bool {
	for i in 2..n-1 {
		if n % i == 0 {
			return false;
		}
	}
	true
}