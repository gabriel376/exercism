const GIGA: number = 1e9;
const SECOND: number = 1e3;
const GIGASECOND: number = GIGA * SECOND;

export default class Gigasecond {
    constructor(private readonly start: Date) {

    }
    date(): Date {
        return new Date(this.start.getTime() + GIGASECOND);
    }
}
