use std::collections::HashMap;

pub struct CodonsInfo<'a> {
    table: HashMap<&'a str, &'a str>
}

impl<'a> CodonsInfo<'a> {
    pub fn name_for(&self, codon: &str) -> Option<&'a str> {
        self.table.get(codon).cloned()
    }

    pub fn of_rna(&self, rna: &str) -> Option<Vec<&'a str>> {
        rna.as_bytes()
            .chunks(3)
            .map(|chunk| String::from_utf8_lossy(chunk))
            .map(|codon| self.name_for(&codon))
            .take_while(|&codon| codon != Some("stop codon"))
            .collect()
    }
}

pub fn parse<'a>(pairs: Vec<(&'a str, &'a str)>) -> CodonsInfo<'a> {
    CodonsInfo {
        table: pairs.iter().cloned().collect()
    }
}
