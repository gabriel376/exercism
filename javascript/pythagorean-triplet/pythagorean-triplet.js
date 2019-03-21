export class Triplet {
    constructor(...sides) {
        this.sides = sides;
    }

    sum() {
        return this.sides.reduce((a, b) => a + b);
    }

    product() {
        return this.sides.reduce((a, b) => a * b);
    }

    isPythagorean() {
        const [a, b, c] = this.sides;
        return c*c == a*a + b*b;
    }

    static where({ minFactor: min=3, maxFactor: max=6, sum: sum }) {
        let triplets = [];

        for (let a = min; a < max; a++) {
            for (let b = a+1; b < max; b++) {
                const c = parseInt(Math.sqrt(a*a + b*b));
                const triplet = new Triplet(a, b, c);
                if (triplet.isPythagorean() && (!sum || triplet.sum() == sum)) {
                    triplets.push(triplet);
                }
            }
        }

        return triplets;
    }
}
