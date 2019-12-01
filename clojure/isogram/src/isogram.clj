(ns isogram)

(defn isogram? [word]
  (->> (clojure.string/lower-case word)
       (filter #(Character/isLetter %))
       (apply distinct?)))
