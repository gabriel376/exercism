def distance(dna1, dna2):
    if len(dna1) != len(dna2):
        raise ValueError("DNAs must have same length")
    return sum(a != b for a, b in zip(dna1, dna2))
