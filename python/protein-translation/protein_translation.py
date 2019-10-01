PROTEINS_BY_NAME = {
    'Methionine': ['AUG'],
    'Phenylalanine': ['UUU', 'UUC'],
    'Leucine': ['UUA', 'UUG'],
    'Serine': ['UCU', 'UCC', 'UCA', 'UCG'],
    'Tyrosine': ['UAU', 'UAC'],
    'Cysteine': ['UGU', 'UGC'],
    'Tryptophan': ['UGG'],
}

PROTEINS_BY_CODON = {codon: protein
                     for (protein, codons) in PROTEINS_BY_NAME.items()
                     for codon in codons}

def codons(strand):
    step = 3
    limit = len(strand)
    for i in range(0, limit, step):
        codon = strand[i:i+step]
        if codon not in PROTEINS_BY_CODON:
            break
        yield codon

def proteins(strand):
    return [PROTEINS_BY_CODON[c] for c in codons(strand)]
