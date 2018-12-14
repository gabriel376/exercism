const transcript = {
    'G': 'C',
    'C': 'G',
    'T': 'A',
    'A': 'U',
};

const error = () => {
    throw new Error('Invalid input DNA.');
};

module.exports = {
    toRna(dna) {
        return Array.from(dna)
            .map(x => transcript[x] || error())
            .join('');
    }
};
