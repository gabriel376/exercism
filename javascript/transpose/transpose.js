export function transpose(array) {
    if (array.length === 0) return [];

    return Array(Math.max(...array.map(row => row.length)))
        .fill()
        .map((_, col) => array.map(row => row[col] || ' ').join(''))
        .map((row, i, arr) => i+1 < arr.length ? row : row.trimRight());
}
