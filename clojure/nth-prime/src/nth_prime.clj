(ns nth-prime)

(defn divisible? [a b]
  (zero? (rem a b)))

(defn prime? [n]
  (not-any? (partial divisible? n) (conj (range 3 (inc (Math/sqrt n)) 2) 2)))

(def primes
  (conj (filter prime? (iterate (partial + 2) 3)) 2))

(defn nth-prime [n]
  (when-not (pos? n)
    (throw (IllegalArgumentException.)))
  (nth primes (dec n)))
