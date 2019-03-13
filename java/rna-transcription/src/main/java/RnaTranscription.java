import java.util.Map;

class RnaTranscription {
    private final static Map<Character, Character> NUCLEOTIDES = Map.of(
        'G', 'C',
        'C', 'G',
        'T', 'A',
        'A', 'U'
    );

    String transcribe(String dna) {
        return dna.chars()
            .map(c -> NUCLEOTIDES.get((char)c))
            .collect(StringBuilder::new,
                     StringBuilder::appendCodePoint,
                     StringBuilder::append)
            .toString();
    }
}
