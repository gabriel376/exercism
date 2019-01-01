const PROTEINS = [{
    name: 'Methionine',
    codons: ['AUG'],
}, {
    name: 'Phenylalanine',
    codons: ['UUU', 'UUC'],
}, {
    name: 'Leucine',
    codons: ['UUA', 'UUG'],
}, {
    name: 'Serine',
    codons: ['UCU', 'UCC', 'UCA', 'UCG'],
}, {
    name: 'Tyrosine',
    codons: ['UAU', 'UAC'],
}, {
    name: 'Cysteine',
    codons: ['UGU', 'UGC'],
}, {
    name: 'Tryptophan',
    codons: ['UGG'],
}, {
    name: null,
    codons: ['UAA', 'UAG', 'UGA', 'UAA'],
}];

const error = () => {
    throw new Error('Invalid codon');
};

const getCodon = (_, i, ar) => i % 3 == 0 ? ar.slice(i, i + 3).join('') : null;
const isCodon = (c) => c && c.length == 3;
const getProtein = (c) => PROTEINS.find(p => p.codons.includes(c)) || error();
const isStop = (p, i, ar) => ar.slice(0, i + 1).findIndex(a => !a.name) < 0;
const getName = (p) => p.name;

module.exports = sequence => {
    return Array.from(sequence || '')
        .map(getCodon)
        .filter(isCodon)
        .map(getProtein)
        .filter(isStop)
        .map(getName);
};
