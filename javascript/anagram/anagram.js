const arrange = string => [...string.toLowerCase()].sort().join();

export class Anagram {
    constructor(word) {
        this.word = word;
    }

    matches(candidates) {
        return candidates
            .filter(this.isAnagram.bind(this));
    }

    isAnagram(candidate) {
        return arrange(candidate) === arrange(this.word)
            && candidate.toLowerCase() !== this.word.toLowerCase();
    }
}
