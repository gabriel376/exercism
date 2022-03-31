(ns cars-assemble)

(defn success-rate
  "Returns the assembly line's success rate,
  taking into account its speed"
  [speed]
  (cond
    (<= 1 speed 4) 1.00
    (<= 5 speed 8) 0.90
    (= 9 speed)    0.80
    (= 10 speed)   0.77
    :else          0.00))

(defn production-rate
  "Returns the assembly line's production rate per hour,
   taking into account its success rate"
  [speed]
  (* 221 speed (success-rate speed)))

(defn working-items
  "Calculates how many working cars are produced per minute"
  [speed]
  (quot (int (production-rate speed)) 60))
