(ns nucleotide-count)

(def nucleotides (zipmap "ACGT" (repeat 0)))

(defn nucleotide-counts [strand]
  {:post [(= (keys nucleotides) (keys %))]}
  (merge nucleotides (frequencies strand)))

(defn count-of-nucleotide-in-strand [nucleotide strand]
  {:pre [(nucleotides nucleotide)]}
  (get (nucleotide-counts strand) nucleotide))
