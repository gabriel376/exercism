(provide 'nucleotide-count)

(defun nucleotide-count (strand)
  "Counts the nucleotides ACGT given a DNA strand"
  (seq-reduce (lambda (xs x)
                (if (assoc x xs)
                    (setcdr (assoc x xs) (+ 1 (cdr (assoc x xs))))
                  (error (format "invalid nucleotide: %c" x)))
                xs)
              strand
              (mapcar (lambda (a) (cons a 0)) "ACGT")))
