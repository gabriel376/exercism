(ns collatz-conjecture)

(defn collatz [n]
  (cond (<= n 0) (throw (Exception. "invalid input"))
        (= n 1)  0
        :else    (+ 1 (collatz (if (odd? n)
                                   (inc (* n 3))
                                   (/ n 2))))))
