(ns sum-of-multiples)

(defn sum-of-multiples [xs x]
  (->> (mapcat #(range % x %) xs)
       distinct
       (apply +)))
