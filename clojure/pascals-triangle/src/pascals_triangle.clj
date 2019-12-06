(ns pascals-triangle)

(defn fact [n]
  "Calculates the factorial"
  (reduce * (range 1N (inc n))))

(defn bin-coef [n k]
  "Calculates the binomial coefficient"
  (/ (fact n)
     (fact k)
     (fact (- n k))))

(defn row [n]
  "Returns the Pascal's Triangle nth row"
  (map #(bin-coef (dec n) %) (range n)))

(def triangle
  "Defines a Pascal's Triangle"
  (drop 1 (map row (range))))
