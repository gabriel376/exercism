import java.util.List;

public class Protein {

    private String name;
    private List<String> codons;

    public Protein(String name, List<String> codons) {
        this.name = name;
        this.codons = codons;
    }

    public String getName() {
        return name;
    }

    public boolean hasCodon(String codon) {
        return codons.contains(codon);
    }
}
