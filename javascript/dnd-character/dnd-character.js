import { Dice } from './dice.js';

const DICE = new Dice(1, 6);
const ABILITIES = [
    'strength',
    'dexterity',
    'constitution',
    'intelligence',
    'wisdom',
    'charisma',
];

export function abilityModifier(input) {
    const min = 3;
    const max = 18;

    if (input < min)
        throw new Error(`Ability scores must be at least ${min}`);

    if (input > max)
        throw new Error(`Ability scores can be at most ${max}`);

    return Math.floor((input - 10) / 2);
}

export class Character {
    static rollAbility() {
        return DICE.roll(4).top(3).sum();
    }

    constructor() {
        return ABILITIES.forEach(ability => {
            this[ability] = Character.rollAbility();
        });
    }

    get hitpoints() {
        return 10 + abilityModifier(this.constitution);
    }
}
