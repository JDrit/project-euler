(defun main ()
  (let ((num (/ (+ (expt 100 4) (* 2 (expt 100 3)) (expt 100 2)) 4)))
    (let ((dem (/ (* 100 (+ 100 1) (+ (* 2 100) 1)) 6)))
      (print (- num dem)))))

