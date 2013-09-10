(defun main ()
	   (let ((count 20))
	     (loop while t do
		  (if (and (= (mod count 19) 0)
			   (= (mod count 18) 0)
			   (= (mod count 17) 0)
			   (= (mod count 16) 0)
			   (= (mod count 15) 0)
			   (= (mod count 14) 0)
			   (= (mod count 13) 0)
			   (= (mod count 12) 0)
			   (= (mod count 11) 0)) (return-from main count))
		  (incf count 20))))

