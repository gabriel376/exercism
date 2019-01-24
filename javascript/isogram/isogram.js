export function isIsogram(word) {
    let letters = word.toLowerCase().match(/[a-z]/g) || [];
    return letters.length == new Set(letters).size;
}
