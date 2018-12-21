struct Bottle {
    n: i32,
}

impl Bottle {
    fn new(n: i32) -> Bottle {
        Bottle {
            n: if n >= 0 { n } else { 99 },
        }
    }

    fn count(&self) -> String {
        let count = if self.n > 0 {
            self.n.to_string()
        } else {
            String::from("No more")
        };
        let plural = if self.n != 1 { "s" } else { "" };
        format!("{} bottle{}", count, plural)
    }

    fn action(&self) -> String {
        String::from(match self.n {
            0 => "Go to the store and buy some more",
            1 => "Take it down and pass it around",
            _ => "Take one down and pass it around",
        })
    }

    fn drink(&self) -> Bottle {
        Bottle::new(self.n - 1)
    }
}

pub fn verse(n: i32) -> String {
    let bottle = Bottle::new(n);
    format!(
        "{} of beer on the wall, {} of beer.\n{}, {} of beer on the wall.\n",
        bottle.count(),
        bottle.count().to_lowercase(),
        bottle.action(),
        bottle.drink().count().to_lowercase()
    )
}

pub fn sing(start: i32, end: i32) -> String {
    (end..start + 1)
        .rev()
        .map(|n| verse(n))
        .collect::<Vec<String>>()
        .join("\n")
}
