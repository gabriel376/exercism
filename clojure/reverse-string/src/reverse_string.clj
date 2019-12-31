(ns reverse-string)

(comment
  (defn reverse-string [s]
    (apply str (reverse s))))

(defn reverse-string [s]
  (reduce #(str %2 %1) "" s))
