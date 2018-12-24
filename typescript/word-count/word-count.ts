class Words {
    count(words: string): Map<string, number> {
        return words.toLowerCase()
            .trim()
            .split(/\s+/)
            .reduce((map, word) => map.set(word, (map.get(word) || 0) + 1), new Map());
    }
}
export default Words;
