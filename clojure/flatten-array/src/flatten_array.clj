(ns flatten-array)

(comment
  (defn flatten [arr]
    (->> arr
         clojure.core/flatten
         (filter some?))))

(defn flatten [arr]
  (->> (mapcat #(if (coll? %) (flatten %) (list %)) arr)
       (filter some?)))
