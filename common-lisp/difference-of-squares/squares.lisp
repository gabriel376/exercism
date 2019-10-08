(defpackage #:squares
  (:use #:cl)
  (:export #:sum-of-squares
           #:square-of-sum
           #:difference))

(in-package #:squares)

(defun numbers (a b fn)
  (mapcar fn
          (loop for n from a to b collect n)))

(defun sum (numbers)
  (reduce '+ numbers))

(defun square (num)
  (expt num 2))

(defun square-of-sum (num)
  (square (sum (numbers 1 num 'identity))))

(defun sum-of-squares (num)
  (sum (numbers 1 num 'square)))

(defun difference (num)
  (- (square-of-sum num)
     (sum-of-squares num)))
