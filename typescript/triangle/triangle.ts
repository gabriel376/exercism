export default class Triangle {
    sides: number[]

    constructor(...sides: number[]) {
        this.sides = sides
    }

    kind(): string {
        if (this.sides.some(x => x <= 0)) {
            throw new Error("invalid side");
        }

        let max: number = Math.max(...this.sides);
        let sum: number = this.sides.reduce((x, y) => x + y, 0);
        if (2 * max > sum) {
            throw new Error("invalid triangle");
        }

        let unique: Set<number> = new Set(this.sides);
        switch (unique.size) {
        case 1:
            return "equilateral";
        case 2:
            return "isosceles";
        default:
            return "scalene";
        }
    }
}
