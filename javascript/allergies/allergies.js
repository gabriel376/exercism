const ALLERGIES = [
    'eggs',
    'peanuts',
    'shellfish',
    'strawberries',
    'tomatoes',
    'chocolate',
    'pollen',
    'cats',
].reduce((obj, str, idx) => {
    obj[1 << idx] = str;
    return obj;
}, {});

export default class Allergies  {
    constructor(value) {
        this.value = value;
    }

    list() {
        return Object.keys(ALLERGIES)
            .filter(x => this.value & x)
            .map(x => ALLERGIES[x]);
    }

    allergicTo(allergy) {
        return this.list()
            .includes(allergy);
    }
};
