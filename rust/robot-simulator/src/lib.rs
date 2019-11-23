#[derive(PartialEq, Debug)]
pub enum Direction {
    North,
    East,
    South,
    West,
}

pub struct Robot {
    x: i32,
    y: i32,
    d: Direction,
}

impl Robot {
    pub fn new(x: i32, y: i32, d: Direction) -> Self {
        Robot { x, y, d }
    }

    pub fn turn_right(self) -> Self {
        match self.d {
            Direction::North => Self::new(self.x, self.y, Direction::East),
            Direction::East  => Self::new(self.x, self.y, Direction::South),
            Direction::South => Self::new(self.x, self.y, Direction::West),
            Direction::West  => Self::new(self.x, self.y, Direction::North),
        }
    }

    pub fn turn_left(self) -> Self {
        match self.d {
            Direction::North => Self::new(self.x, self.y, Direction::West),
            Direction::West  => Self::new(self.x, self.y, Direction::South),
            Direction::South => Self::new(self.x, self.y, Direction::East),
            Direction::East  => Self::new(self.x, self.y, Direction::North),
        }
    }

    pub fn advance(self) -> Self {
        match self.d {
            Direction::North => Self::new(self.x, self.y + 1, self.d),
            Direction::South => Self::new(self.x, self.y - 1, self.d),
            Direction::East  => Self::new(self.x + 1, self.y, self.d),
            Direction::West  => Self::new(self.x - 1, self.y, self.d),
        }
    }

    pub fn instructions(self, instructions: &str) -> Self {
        instructions.chars().fold(self, |robot, c| match c {
            'L' => robot.turn_left(),
            'R' => robot.turn_right(),
            'A' => robot.advance(),
            _   => robot,
        })
    }

    pub fn position(&self) -> (i32, i32) {
        (self.x, self.y)
    }

    pub fn direction(&self) -> &Direction {
        &self.d
    }
}
