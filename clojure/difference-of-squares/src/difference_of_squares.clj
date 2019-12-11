(ns difference-of-squares)

(defn numbers [n]
  (range 1 (inc n)))

(defn sum [ns]
  (apply + ns))

(defn square [n]
  (* n n))

(defn sum-of-squares [n]
  (->> (numbers n)
       (map square)
       sum))

(defn square-of-sum [n]
  (->> (numbers n)
       sum
       square))

(defn difference [n]
  (- (square-of-sum n)
     (sum-of-squares n)))
