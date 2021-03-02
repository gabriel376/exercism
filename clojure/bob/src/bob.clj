(ns bob
  (:require [clojure.string :as string]))

(defn- question? [text]
  (string/ends-with? (string/trim text) "?"))

(defn- yell? [text]
  (and (= text (string/upper-case text))
       (re-find #"[A-Z]" text)))

(defn- gibberish? [text]
  (string/blank? text))

(defn response-for [text]
  (cond
    (gibberish? text)     "Fine. Be that way!"
    (and (question? text)
         (yell? text))    "Calm down, I know what I'm doing!"
    (question? text)      "Sure."
    (yell? text)          "Whoa, chill out!"
    :else                 "Whatever."))
