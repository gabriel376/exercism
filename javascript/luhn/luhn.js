export class Luhn {
  constructor(input) {
    const numbers = [...input]
      .filter(x => x !== " ")
      .map(Number);
    const sum = numbers
      .reverse()
      .map((x, i) => (i % 2 ? 2 * x : x))
      .map(x => (x > 9 ? x - 9 : x))
      .reduce((a, b) => a + b);
    this.valid = numbers.length > 1 && sum % 10 == 0;
  }
}

