(defun main ()
  (let ((sum 0)(x 1)(y 2)(tmp 0))
    (incf sum 2)
    (loop for tmp from 3 below 4000000 do
	    (setf tmp (+ x y))
	    (if (evenp tmp) (incf sum tmp))
	    (setf x y)
	    (setf y tmp))
	(print sum)))

