(ns raindrops)

(defn convert [number]
  (->> {3 "Pling", 5 "Plang", 7 "Plong"}
       (filter #(zero? (rem number (first %))))
       (map second)
       (apply str)
       (#(if (empty? %) (str number) %))))
