(ns gigasecond)

(defn from [y m d]
  (-> (java.time.LocalDateTime/of y m d 0 0)
       (.plusSeconds 1e9)
       ((juxt #(.getYear %) #(.getMonthValue %) #(.getDayOfMonth %)))))
