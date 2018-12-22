const SCORES = [
    {
        from: 0,
        to: 1,
        value: 10,
    },
    {
        from: 1,
        to: 5,
        value: 5,
    },
    {
        from: 5,
        to: 10,
        value: 1,
    },
    {
        from: 10,
        to: Number.MAX_SAFE_INTEGER,
        value: 0,
    }
];

export const solve = (x, y) => {
    let dist = Math.sqrt(x*x + y*y);
    return isNaN(dist)
        ? null
        : SCORES.find(s => dist >= s.from && dist <= s.to).value;
}
