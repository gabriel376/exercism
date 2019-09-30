use std::collections::{BTreeMap, BTreeSet};

type Grade    = u32;
type Students = BTreeSet<String>;
type Database = BTreeMap<Grade, Students>;

#[derive(Default)]
pub struct School {
    database: Database,
}

impl School {
    pub fn new() -> School {
        Default::default()
    }

    pub fn add(&mut self, grade: Grade, student: &str) {
        self.database
            .entry(grade)
            .or_insert_with(Students::new)
            .insert(student.to_string());
    }

    pub fn grades(&self) -> Vec<u32> {
        self.database
            .keys()
            .cloned()
            .collect()
    }

    pub fn grade(&self, grade: Grade) -> Option<Vec<String>> {
        self.database
            .get(&grade)
            .map(|students| students.iter().cloned().collect())
    }
}
