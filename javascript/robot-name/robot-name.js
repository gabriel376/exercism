function range(min, max) {
    return Array(max - min + 1)
        .fill()
        .map((_, i) => i + min);
}

function product(...xs) {
  if (xs.length === 1) return xs[0];
  const arr = [];
  for (let v1 of xs[0])
    for (let v2 of xs[1])
      arr.push(v1 + v2);
  return product.apply(null, [arr, ...xs.slice(2)])
}

function shuffle(xs) {
    let currentIndex = xs.length;
    for (let i = xs.length; i >= 0; i--) {
        const j = Math.floor(Math.random() * i);
        [xs[i], xs[j]] = [xs[j], xs[i]];
    }
    return xs;
}

const LETTERS = range('A'.charCodeAt(0), 'Z'.charCodeAt(0))
      .map(c => String.fromCharCode(c));

const DIGITS = range(0, 9);

const NAMES = shuffle(product(LETTERS, LETTERS, DIGITS, DIGITS, DIGITS));

export class Robot {
    static _names = NAMES.slice(0);

    constructor() {
        this.reset();
    }

    reset() {
        this._name = Robot._names.pop();
    }

    get name() {
        return this._name;
    }

    static releaseNames() {
        Robot._names = NAMES.slice(0);
    }
}
