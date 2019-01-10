PROTEINS_BY_NAME = {
    'Methionine': ['AUG'],
    'Phenylalanine': ['UUU', 'UUC'],
    'Leucine': ['UUA', 'UUG'],
    'Serine': ['UCU', 'UCC', 'UCA', 'UCG'],
    'Tyrosine': ['UAU', 'UAC'],
    'Cysteine': ['UGU', 'UGC'],
    'Tryptophan': ['UGG'],
}

PROTEINS_BY_CODON = {v: k for k in PROTEINS_BY_NAME for v in PROTEINS_BY_NAME[k]}

def proteins(strand):
    step = 3
    until = len(strand)
    codons = [strand[i:i+step] for i in range(0, until, step) if i+step <= until]
    stop = [i for i, e in enumerate(codons) if not e in PROTEINS_BY_CODON]
    if len(stop) > 0:
        codons = codons[0:stop[0]]
    proteins = [PROTEINS_BY_CODON[c] for c in codons]
    return proteins
