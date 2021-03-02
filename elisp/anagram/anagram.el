;;; anagram.el --- Anagram (exercism)

;;; Commentary:

;;; Code:

(defun string-to-sorted-list (string)
  "Converts a `STRING' to a sorted list."
  (seq-sort '< (string-to-list string)))

(defun anagram-p (word1 word2)
  "Checks if `WORD1' is an anagram of `WORD2', or vice-versa."
  (let ((word1 (downcase word1))
        (word2 (downcase word2)))
    (and (not (equal word1 word2))
         (equal (string-to-sorted-list word1)
                (string-to-sorted-list word2)))))

(defun anagrams-for (word candidates)
  "Find anagrams for `WORD' in the list of `CANDIDATES'."
  (seq-filter (apply-partially 'anagram-p word)
              candidates))

(provide 'anagram)
;;; anagram.el ends here
