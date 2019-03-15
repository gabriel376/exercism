class DnDCharacter {
    private Dice dice = new Dice(6);
    private int constitution = ability();
    private int strength = ability();
    private int charisma = ability();
    private int wisdom = ability();
    private int intelligence = ability();
    private int dexterity = ability();

    int ability() {
        return dice.roll(4).top(3).sum();
    }

    int modifier(int input) {
        return Math.floorDiv(input - 10, 2);
    }

    int getHitpoints() {
        return 10 + modifier(getConstitution());
    }

    int getConstitution() {
        return constitution;
    }

    int getStrength() {
        return strength;
    }

    int getCharisma() {
        return charisma;
    }

    int getWisdom() {
        return wisdom;
    }

    int getIntelligence() {
        return intelligence;
    }

    int getDexterity() {
        return dexterity;
    }
}
