(ns leap)

(defn div? [a b]
  (zero? (mod a b)))

(defn leap-year? [year]
  (or (div? year 400)
      (and (div? year 4)
           (not (div? year 100)))))
