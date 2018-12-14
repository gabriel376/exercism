pub fn find() -> Option<u32> {
	let max = 998;
    for a in 1..max {
    	for b in a+1..max {
    		for c in b+1..max {
    			if is_pythagorean_triplet(a, b, c) && check_cond(a, b, c) {
    				return Some(a * b * c);
    			}
    		}
    	}
    }
    None
}

fn is_pythagorean_triplet(a: u32, b: u32, c: u32,) -> bool {
	(a * a) + (b * b) == (c * c)
}

fn check_cond(a: u32, b: u32, c: u32,) -> bool {
	a + b + c == 1000
}
