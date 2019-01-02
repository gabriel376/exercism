export default class Triangle {
    constructor(a, b, c) {
        this.sides = { a, b, c };
    }

    kind() {
        let { a, b, c } = this.sides;

        if (a <= 0 || b <= 0 || c <= 0)
            throw new Error('invalid side');

        if (a > b + c || b > a + c || c > a + b)
            throw new Error('not a triangle');

        return a == b && a == c
            ? 'equilateral'
            : a == b || a == c || b == c
            ? 'isosceles'
            : 'scalene'
    }
}
