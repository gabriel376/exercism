const SCORES = [
    { from: 0,  to: 1,  value: 10 },
    { from: 1,  to: 5,  value: 5  },
    { from: 5,  to: 10, value: 1  },
];

export function score(x, y) {
    let dist = Math.sqrt(x*x + y*y);
    let score = SCORES.find(s => dist >= s.from && dist <= s.to);
    return score && score.value || 0
}
