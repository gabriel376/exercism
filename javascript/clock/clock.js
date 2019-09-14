const DAY = 24 * 60;

export class Clock {
    constructor(hh, mm=0) {
        this.minutes = (hh*60 + mm) % DAY;
        if (this.minutes < 0) {
            this.minutes += DAY;
        }
    }

    toString() {
        return [this.minutes/60, this.minutes%60]
            .map(Math.floor)
            .map(String)
            .map(val => val.padStart(2, '0'))
            .join(':');
    }

    plus(mm) {
        return new Clock(0, this.minutes + mm);
    }

    minus(mm) {
        return new Clock(0, this.minutes - mm);
    }

    equals(other) {
        return this.minutes === other.minutes;
    }
}
