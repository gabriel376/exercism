class ArmstrongNumbers {

	boolean isArmstrongNumber(int number) {
        String str = Integer.toString(number);
        return number == str
            .chars()
            .map(c -> (int) Math.pow(c - '0', str.length()))
            .sum();
    }
}
