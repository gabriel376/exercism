(ns perfect-numbers)

(defn factors [number]
  (filter #(zero? (mod number %))
          (range 1 number)))

(defn classify [number]
  (when (neg? number)
    (throw (IllegalArgumentException. "negative numbers not allowed")))
  (-> (apply + (factors number))
      (compare number)
      (case -1 :deficient
             0 :perfect
             1 :abundant)))
