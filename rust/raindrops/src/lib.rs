pub fn raindrops(num: usize) -> String {
    let mut msg = String::from("");

    let mut drop = |fac, str| {
        if num % fac == 0 {
            msg.push_str(str);
            return true;
        }
        return false;
    };

    match (drop(3, "Pling"), drop(5, "Plang"), drop(7, "Plong")) {
        (false, false, false) => num.to_string(),
        (_, _, _) => msg,
    }
}
