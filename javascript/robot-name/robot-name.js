import NamesFactory from './names-factory.js';

export class Robot {
    constructor() {
        this.reset();
    }

    reset() {
        this._name = Robot.namesFactory.next();
    }

    get name() {
        return this._name;
    }

    static releaseNames() {
        Robot.namesFactory = new NamesFactory();
    }
}

Robot.releaseNames();
