function range(min, max) {
    return Array(max - min + 1)
        .fill()
        .map((_, i) => i + min);
}

function combine(array) {
    return array.reduce((acc, val) => {
        const temp = [];
        acc.forEach(a =>
            val.forEach(b =>
                temp.push(a.concat(b))
            )
        );
        return temp;
    }, [[]]);
}

function shuffle(array) {
    array.forEach((val, idx) => {
        const rnd = Math.floor(Math.random() * array.length);
        const temp = array[idx];
        array[idx] = array[rnd];
        array[rnd] = temp;
    });

    return array;
}

function copy(array) {
    return array.slice(0);
}

const LETTERS = range('A'.charCodeAt(0), 'Z'.charCodeAt(0))
    .map(c => String.fromCharCode(c));

const NUMBERS = range(0, 9);

const NAMES = shuffle(combine([
    LETTERS, LETTERS, NUMBERS, NUMBERS, NUMBERS
]));

export default class NamesFactory {
    constructor() {
        this.names = copy(NAMES);
    }

    next() {
        const name = this.names.pop();
        if (name) {
            return name.join('');
        }
        return null;
    }
}
