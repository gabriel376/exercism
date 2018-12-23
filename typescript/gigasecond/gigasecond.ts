class Gigasecond {
    private _date: Date;
    constructor(d: Date) {
        this._date = new Date(d.getTime() + 1e12);
    }
    date(): Date {
        return this._date;
    }
}

export default Gigasecond;
