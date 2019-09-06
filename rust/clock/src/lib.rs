use std::fmt;

const DAY: i32 = 24 * 60;

#[derive(Debug, Eq, PartialEq)]
pub struct Clock {
    minutes: i32,
}

impl Clock {
    pub fn new(hh: i32, mm: i32) -> Self {
        let mut minutes = (hh*60 + mm) % DAY;
        if minutes < 0 {
            minutes += DAY;
        }

        Clock {
            minutes,
        }
    }

    pub fn add_minutes(&self, mm: i32) -> Self {
        Clock::new(0, self.minutes + mm)
    }
}

impl fmt::Display for Clock {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{:02}:{:02}",
               self.minutes / 60,
               self.minutes % 60)
    }
}
