(ns armstrong-numbers)

(defn char-to-digit [c]
  (- (int c) (int \0)))

(defn get-digits [number]
  (map char-to-digit (str number)))

(defn power [base exp]
  (reduce * (repeat exp base)))

(defn to-armstrong [number]
  (def digits (get-digits number))
  (def len (count digits))
  (->> digits
       (map #(power % len))
       (apply +)))

(defn armstrong? [number]
  (= number (to-armstrong number)))
