import Notifier from './notifier';

export default class CallbackCell {
    constructor(callback) {
        this.callback = callback;
        this.values = [];
        this.Notifier = new Notifier();
    }

    update(cell) {
        this.values.push(this.callback(cell));
    }
};
