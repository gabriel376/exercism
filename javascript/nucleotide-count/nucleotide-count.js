const error = () => {
    throw new Error('Invalid nucleotide in strand');
};

export default class NucleotideCounts {
    static parse(sequence) {
        const count = {
            A: 0,
            C: 0,
            G: 0,
            T: 0,
        };

        Array.from(sequence)
            .forEach(x => count.hasOwnProperty(x)
                     ? count[x]++
                     : error());

        return Object.keys(count)
            .map(x => count[x])
            .join(' ');
    }
};
