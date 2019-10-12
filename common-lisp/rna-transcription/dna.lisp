(in-package #:cl-user)
(defpackage #:dna
  (:use #:cl)
  (:export #:to-rna))
(in-package #:dna)

(defun swap-nuc (nuc)
  (case nuc
    (#\A #\U)
    (#\C #\G)
    (#\G #\C)
    (#\T #\A)))

(defun to-rna (dna)
  (map 'string 'swap-nuc dna))
