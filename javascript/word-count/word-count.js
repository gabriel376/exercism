export class Words {
    count(phrase) {
        return phrase.toLowerCase()
            .split(/\s/g)
            .filter(s => s.length > 0)
            .reduce((words, word) => {
               if (!words.hasOwnProperty(word))
                    words[word] = 0;
                words[word] += 1;
                return words;
            }, {});
    }
}








