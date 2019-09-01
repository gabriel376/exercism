use std::collections::HashMap;

pub fn count(nucleotide: char, dna: &str) -> Result<usize, char> {
    if !"ACGT".contains(nucleotide) {
        return Err(nucleotide);
    }

    dna.chars().try_fold(0, |tot, nuc| {
        match nuc {
            nuc if nuc == nucleotide => Ok(tot + 1),
            'A' | 'C' | 'G' | 'T' => Ok(tot),
            _ => Err(nuc),
        }
    })
}

pub fn nucleotide_counts(dna: &str) -> Result<HashMap<char, usize>, char> {
    "ACGT".chars()
        .map(|nuc| Ok((nuc, count(nuc, dna)?)))
        .collect()
}
