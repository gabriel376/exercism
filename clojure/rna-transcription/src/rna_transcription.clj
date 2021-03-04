(ns rna-transcription)

(defn ^:private transcript [nucleotide]
  (condp = nucleotide
    \G \C
    \C \G
    \T \A
    \A \U
    (throw (AssertionError. "Invalid nucleotide."))))

(defn to-rna [dna]
  (->> dna
       (map transcript)
       (apply str)))
