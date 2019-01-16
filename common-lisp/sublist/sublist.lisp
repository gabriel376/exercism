(defpackage #:sublist
  (:use #:common-lisp)
  (:export #:sublist))

(in-package #:sublist)

(defun sublist (list1 list2)
  (cond ((equal list1 list2) :equal)
        ((search list1 list2) :sublist)
        ((search list2 list1) :superlist)
        (t :unequal)))
