(ns pangram)

(defn pangram? [text]
  (->> (filter #(Character/isLetter %) text)
       (map clojure.string/lower-case)
       set
       count
       (= 26)))
