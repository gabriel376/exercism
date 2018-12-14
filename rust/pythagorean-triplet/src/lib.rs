struct Triangle {
    pub a: u32,
    pub b: u32,
    pub c: u32,
}

impl Triangle {
    pub fn new(a: u32, b: u32, c: u32) -> Triangle {
        Triangle {
            a,
            b,
            c
        }
    }
    
    pub fn is_pythagorean(&self) -> bool {
        (self.a * self.a) + (self.b * self.b) == (self.c * self.c)
    }
    
    pub fn sum(&self) -> u32 {
        self.a + self.b + self.c
    }
    
    pub fn product(&self) -> u32 {
        self.a * self.b * self.c
    }
}

struct Triangles {
    max: u32,
    a: u32,
    b: u32,
    c: u32,
}

impl Triangles {
    pub fn new(max: u32) -> Triangles {
        if max < 3 {
            panic!("max should be greater or equal to 3.");
        }
        
        Triangles{
            max,
            a: 1,
            b: 2,
            c: 2,
        }
    }
}

impl Iterator for Triangles {
    type Item = Triangle;
    
    fn next(&mut self) -> Option<Self::Item> {
        self.c += 1;
        if self.c > self.max {
            self.b += 1;
            self.c = self.b + 1;
            if self.c > self.max {
                self.a += 1;
                self.b = self.a + 1;
                self.c = self.b + 1;
                if self.c > self.max {
                    return None;
                }
            }
        }
        
        Some(Triangle::new(self.a, self.b, self.c))
    }
}

pub fn find() -> Option<u32> {
    let sum = 1000;
    let triangles = Triangles::new(sum);
    for t in triangles.filter(|x| x.is_pythagorean() && x.sum() == sum ) {
        return Some(t.product());
    }
    None
}
