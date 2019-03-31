export class Series {
    constructor(input) {
        this.digits = [...input].map(Number);
    }

    slices(len) {
        if (len > this.digits.length) {
            throw new Error('Slice size is too big.');
        }
        return Array(this.digits.length-len+1).fill(null)
            .map((_, i) => this.digits.slice(i, i+len))
    }
}
