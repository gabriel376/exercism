import InputCell from './inputCell';

export default class ComputeCell extends InputCell {
    constructor(inputs, computer) {
        super(computer(inputs));

        this.inputs = inputs;
        this.computer = computer;

        inputs.forEach(input => input.Notifier.on('InputCellUpdated', this, 'update'));
    }

    update() {
        const value = this.computer(this.inputs);
        if (this.value !== value) {
            this.value = value;
            this.Notifier.notify('ComputeCellUpdated');
        }
    }

    addCallback(cell) {
        this.Notifier.on('ComputeCellUpdated', cell, 'update', () => this);
    }

    removeCallback(cell) {
        this.Notifier.cancel('ComputeCellUpdated', cell, 'update');
    }
};
