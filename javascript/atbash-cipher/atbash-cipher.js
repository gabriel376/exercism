const toCode = (c) => c.charCodeAt();
const fromCode = (c) => String.fromCharCode(c);

const A = toCode('a');
const Z = toCode('z');
const GROUP = 5;

const transform = s => Number(s) ? s : fromCode(A + Z - toCode(s));
const isAlphanumeric = s => Number(s) || (toCode(s) >= A && toCode(s) <= Z);
const group = (s, i) => (i + 1) % GROUP == 0 ? s + ' ' : s;

export const encode = (text) => {
    return Array
        .from(text.toLowerCase())
        .map(transform)
        .filter(isAlphanumeric)
        .map(group)
        .join('')
        .trim();
};
