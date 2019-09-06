import java.util.List;
import java.util.Arrays;
import java.util.Objects;
import java.util.stream.IntStream;
import java.util.stream.Collectors;

class ProteinTranslator {

    private int CODON_SIZE = 3;

    private static List<Protein> PROTEINS = Arrays.asList(
        new Protein("Methionine",    Arrays.asList("AUG")),
        new Protein("Tryptophan",    Arrays.asList("UGG")),
        new Protein("Phenylalanine", Arrays.asList("UUU", "UUC")),
        new Protein("Leucine",       Arrays.asList("UUA", "UUG")),
        new Protein("Tyrosine",      Arrays.asList("UAU", "UAC")),
        new Protein("Cysteine",      Arrays.asList("UGU", "UGC")),
        new Protein("Serine",        Arrays.asList("UCU", "UCC", "UCA", "UCG"))
    );

    public List<String> translate(String sequence) {
        return IntStream.rangeClosed(0, sequence.length() - CODON_SIZE)
            .mapToObj(n -> getCodon(sequence, n))
            .filter(this::isCodon)
            .map(this::getProtein)
            .takeWhile(Objects::nonNull)
            .map(Protein::getName)
            .collect(Collectors.toList());
    }

    private String getCodon(String sequence, int n) {
        return n % CODON_SIZE == 0
            ? sequence.substring(n, n + CODON_SIZE)
            : null;
    }

    private boolean isCodon(String codon) {
        return codon != null;
    }

    private Protein getProtein(String codon) {
        return PROTEINS.stream()
            .filter(p -> p.hasCodon(codon))
            .findFirst()
            .orElse(null);
    }
}
