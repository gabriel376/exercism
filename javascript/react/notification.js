export default class Notification {
    constructor(evt, obj, func, args=() => {}) {
        this.evt = evt;
        this.obj = obj;
        this.func = func;
        this.args = args;
    }

    fire() {
        this.obj[this.func](this.args());
    }

    equals(other) {
        return this.evt  === other.evt
            && this.obj  === other.obj
            && this.func === other.func;
    }
}
