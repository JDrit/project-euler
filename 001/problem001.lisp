(defun main (top)
  (let ((sum 0))
    (dotimes (n top)
      (if (or (eq (mod n 3) 0) (eq (mod n 5) 0))
        (incf sum n)))
    (print sum)))
