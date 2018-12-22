export const compute = (left, right) => {
    if (left.length != right.length)
        throw new Error('left and right strands must be of equal length');
    return Array.from(left)
        .reduce((acc, cur, idx) => cur == right[idx] ? acc : acc + 1, 0);
};
