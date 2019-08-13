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

impl ToString for Clock {
    fn to_string(&self) -> String {
        format!("{:02}:{:02}",
                self.minutes / 60,
                self.minutes % 60)
    }
}
