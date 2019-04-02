export function largestProduct(input, len) {
    if (isNaN(+input) || len < 0) {
        throw new Error('Invalid input.');
    }

    if (len > input.length) {
        throw new Error('Slice size is too big.');
    }

    if (!input || len === 0) {
        return 1;
    }

    const products = Array(input.length - len + 1)
        .fill(null)
        .map((_, i) => input.slice(i, i + len))
        .map(n => [...n].map(Number).reduce((a, b) => a * b));

    return Math.max(...products);
}
