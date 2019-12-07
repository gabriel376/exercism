(ns pascals-triangle)

(def triangle
  "Defines a Pascal's Triangle"
  (iterate (fn [row]
             (->> (concat '(0) row '(0))
                  (partition 2 1)
                  (map (partial reduce +))))
           '(1N)))

(defn row [n]
  "Returns the Pascal's Triangle nth row"
  (nth triangle (dec n)))
