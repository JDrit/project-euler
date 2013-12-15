(defun same-makeup (num1 num2)
  (let ((list-1 (map 'list #'digit-char-p (prin1-to-string num1)))
	(list-2 (map 'list #'digit-char-p (prin1-to-string num2))))
    (equal (sort list-1 #'<) (sort list-2 #'<))))

(defun main ()
  (loop for n from 10 while t do
       (when (and (same-makeup n (* 2 n))
		   (same-makeup n (* 3 n))
		   (same-makeup n (* 4 n))
		   (same-makeup n (* 5 n))
		   (same-makeup n (* 6 n)))
	 (format t "answer: ~d~%" n)
	 (return))))
