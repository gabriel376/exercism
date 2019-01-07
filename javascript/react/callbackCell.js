import Notifier from './notifier';

export default class CallbackCell {
    constructor() {
        this.values = [];
        this.Notifier = new Notifier();
    }

    update(value) {
        this.values.push(value);
    }
};
