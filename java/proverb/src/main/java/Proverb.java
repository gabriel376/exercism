class Proverb {
    private String[] words;

    Proverb(String[] words) {
        this.words = words;
    }

    String recite() {
        StringBuilder proverb = new StringBuilder();

        for (int i = 0; i < words.length -1; i++) {
            String verse = String.format("For want of a %s the %s was lost.\n", words[i], words[i+1]);
            proverb.append(verse);
        }

        if (words.length > 0) {
            String verse = String.format("And all for the want of a %s.", words[0]);
            proverb.append(verse);
        }

        return proverb.toString();
    }
}
