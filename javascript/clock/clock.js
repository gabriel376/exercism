function pad(num, wid=2, sym='0') {
    const str = num.toString();
    const len = str.length;
    return len < wid
        ? new Array(wid-len+1).join(sym) + str
        : str;
}

export class Clock {
    constructor(hh, mm=0) {
        hh += parseInt(mm / 60);
        hh %= 24;
        if (hh < 0) {
            hh += 24;
        }

        mm %= 60;
        if (mm < 0) {
            mm += 60;
            hh = hh == 0 ? 23 : hh - 1;
        }

        this.mm = mm;
        this.hh = hh;
    }

    toString() {
        return `${pad(this.hh)}:${pad(this.mm)}`;
    }

    plus(mm) {
        return new Clock(this.hh, this.mm + mm);
    }

    minus(mm) {
        return new Clock(this.hh, this.mm - mm);
    }

    equals(other) {
        return this.hh === other.hh
            && this.mm === other.mm;
    }
}
