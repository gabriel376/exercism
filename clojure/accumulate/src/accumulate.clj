(ns accumulate)

(defn accumulate [fn xs]
  (reduce #(conj %1 (fn %2)) [] xs))
