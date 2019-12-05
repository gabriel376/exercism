(ns grains)

(defn square [n]
  (->> (bigint 2)
       (repeat (dec n))
       (reduce *)))

(defn total []
  (->> (square 65)
       dec))
