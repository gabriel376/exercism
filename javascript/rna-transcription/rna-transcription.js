const transcript = {
    'G': 'C',
    'C': 'G',
    'T': 'A',
    'A': 'U',
};

const error = () => {
    throw new Error('Invalid input DNA.');
};

export const toRna = dna => {
    return Array.from(dna)
        .map(x => transcript[x] || error())
        .join('');
};
