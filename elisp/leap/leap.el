(provide 'leap)

(defun div-by-p (a b)
  "Returns true if a is divisible by b."
  (zerop (mod a b)))

(defun leap-year-p (year)
  "Returns true if year is a leap year."
  (or (div-by-p year 400)
      (and (div-by-p year 4)
           (not (div-by-p year 100)))))
