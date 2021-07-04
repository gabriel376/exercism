;;; roman-numerals.el --- roman-numerals Exercise (exercism)

;;; Commentary:

;;; Code:

(provide 'roman-numerals)

(defvar roman-numerals--alist
  '((1000 . "M")
    (900 . "CM")
    (500 . "D")
    (400 . "CD")
    (100 . "C")
    (90 . "XC")
    (50 . "L")
    (40 . "XL")
    (10 . "X")
    (9 . "IX")
    (5 . "V")
    (4 . "IV")
    (1 . "I"))
  "Association list of roman numerals.")

(defun to-roman (number)
  "Convert from NUMBER to roman numeral."
  (seq-reduce (lambda (acc item)
                (let ((count (/ number (car item))))
                  (setq number (- number (* count (car item))))
                  (apply #'concat (append (list acc)
                                          (make-list count (cdr item))))))
              roman-numerals--alist
              ""))

;;; roman-numerals.el ends here
