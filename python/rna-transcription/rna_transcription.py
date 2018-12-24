def to_rna(dna):
    transcript = {
        'A': 'U',
        'C': 'G',
        'G': 'C',
        'T': 'A',
    }
    return ''.join([transcript[s] for s in dna])
