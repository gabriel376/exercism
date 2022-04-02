(ns sieve)

(defn sieve [max]
  (:primes
   (reduce (fn [{:keys [primes marked]} n]
             {:primes (if (marked n) primes (conj primes n))
              :marked (reduce conj marked (range (* 2 n) (inc max) n))})
           {:primes [] :marked #{}}
           (range 2 (inc max)))))
