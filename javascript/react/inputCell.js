import Notifier from './notifier';

export default class InputCell {
    constructor(value) {
        this.Notifier = new Notifier();
        this.value = value;
    }

    setValue(value) {
        if (this.value !== value) {
            this.value = value;
            this.Notifier.notify('InputCellUpdated');
        }
    }
};
