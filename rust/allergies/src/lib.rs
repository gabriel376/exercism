#[derive(Debug, PartialEq, Copy, Clone)]
pub enum Allergen {
    Eggs,
    Peanuts,
    Shellfish,
    Strawberries,
    Tomatoes,
    Chocolate,
    Pollen,
    Cats,
}

impl Allergen {
    pub fn value(&self) -> i32 {
        1 << *self as i32
    }

    pub fn vec() -> Vec<Allergen> {
        vec![
            Allergen::Eggs,
            Allergen::Peanuts,
            Allergen::Shellfish,
            Allergen::Strawberries,
            Allergen::Tomatoes,
            Allergen::Chocolate,
            Allergen::Pollen,
            Allergen::Cats,
        ]
    }
}

pub struct Allergies {
    score: i32,
}

impl Allergies {
    pub fn new(score: i32) -> Self {
        Allergies {
            score
        }
    }

    pub fn is_allergic_to(&self, allergen: &Allergen) -> bool {
        self.score & allergen.value() > 0
    }

    pub fn allergies(&self) -> Vec<Allergen> {
        Allergen::vec()
            .iter()
            .filter(|a| self.is_allergic_to(a))
            .cloned()
            .collect()
    }
}
