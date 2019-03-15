import java.util.Random;

class Dice {
    private int max;
    private Random random = new Random();

    Dice(int max) {
        this.max = max;
    }

    DiceResult roll(int times) {
        DiceResult result = new DiceResult();

        for (int i = 0; i < times; i++) {
            int value = random.nextInt(max) + 1;
            result.add(value);
        }

        return result;
    }
}
