const SCORES_BY_VALUE = {
    1: ['A', 'E', 'I', 'O', 'U', 'L', 'N', 'R', 'S', 'T'],
    2: ['D', 'G'],
    3: ['B', 'C', 'M', 'P'],
    4: ['F', 'H', 'V', 'W', 'Y'],
    5: ['K'],
    8: ['J', 'X'],
    10: ['Q', 'Z'],
};

const pivot = (arr) => {
    let temp = {};
    Object.keys(arr).forEach(a => {
        arr[a].forEach(b => {
            temp[b] = parseInt(a);
        });
    });
    return temp;
};

const SCORES_BY_LETTER = pivot(SCORES_BY_VALUE);

export const score = str => {
    return Array.from(str.toUpperCase())
        .reduce((a, b) => a + SCORES_BY_LETTER[b], 0);
};
