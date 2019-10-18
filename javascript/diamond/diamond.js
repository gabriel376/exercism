/*
 * Creates an array of integers mirrored
 * Example: mirror(7) = [0, 1, 2, 3, 2, 1, 0]
 */
function mirror(len) {
    const calc = (_, n) => Math.min(n, len - n - 1);
    return Array(len).fill().map(calc);
}

/*
 * Replaces char at index in string
 * Example: setChar('hello', 1, 'x') = 'hxllo'
 */
function setChar(str, idx, chr) {
    return str.substr(0, idx)
         + chr
         + str.substr(idx + 1);
}

/*
 * Creates a diamond shape of letters
 * Example: new Diamond().makeDiamond('C') = '  A  '
 *                                           ' B B '
 *                                           'C   C'
 *                                           ' B B '
 *                                           '  A  '
 */
export class Diamond {
    makeDiamond(chr) {
        const mid = chr.charCodeAt(0) - 'A'.charCodeAt(0);
        const len = 2 * mid + 1;
        const buildRow = n => {
            const chr =  String.fromCharCode('A'.charCodeAt(0) + n);
            let str = ' '.repeat(len);
            str = setChar(str, mid - n, chr);
            str = setChar(str, mid + n, chr);
            return str;
        }
        return mirror(len).map(buildRow).join('\n') + '\n';
    }
}
