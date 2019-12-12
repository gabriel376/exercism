#[derive(Debug, PartialEq)]
pub struct DNA {
    strand: String,
}

#[derive(Debug, PartialEq)]
pub struct RNA {
    strand: String,
}

impl DNA {
    pub fn new(strand: &str) -> Result<DNA, usize> {
        let result = strand.chars().position(|c| match c {
            'A' | 'C' | 'G' | 'T' => false,
            _ => true,
        });

        match result {
            Some(n) => Err(n),
            None => Ok(DNA {
                strand: strand.to_string(),
            }),
        }
    }

    pub fn into_rna(self) -> RNA {
        let strand = self.strand.chars().map(|c| match c {
                'A' => 'U',
                'C' => 'G',
                'G' => 'C',
                'T' => 'A',
                _ => c,
            }).collect();

        RNA {
            strand
        }
    }
}

impl RNA {
    pub fn new(strand: &str) -> Result<RNA, usize> {
        let result = strand.chars().position(|c| match c {
            'A' | 'C' | 'G' | 'U' => false,
            _ => true,
        });

        match result {
            Some(n) => Err(n),
            None => Ok(RNA {
                strand: strand.to_string(),
            }),
        }
    }
}
