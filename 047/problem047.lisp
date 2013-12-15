(defun factors (n)
  (let ((facts (make-array 0 :fill-pointer 0 :adjustable t))
    (check 2)
    (root (sqrt n)))
    (vector-push-extend 1 facts)
    (vector-push-extend n facts)
    (loop while (< check root) do
          (when (= (mod n check) 0)
            (vector-push-extend check facts)
            (vector-push-extend (/ n check) facts))
          (incf check))
    (if (= root check)
      (vector-push-extend check facts))
    (return-from factors (merge 'list (sort facts #'<) #() #'< ))))

(defun atkin-sieve (limit)
    (let ((results (make-array 0 :fill-pointer 0 :adjustable t :element-type 'fixnum))
	    (sieve (make-array (+ limit 1) :initial-element nil :element-type 'boolean))
		(factor (+ (truncate(sqrt limit)) 1)))
	    (vector-push-extend 2 results)
	    (vector-push-extend 3 results)
	    (vector-push-extend 5 results)
        (loop for i from 1 to factor do
		    (loop for j from 1 to factor do
		        (let ((n (+ (* 4 (expt i 2)) (expt j 2))))
			        (when (and (<= n limit) (or (= (mod n 12) 1) (= (mod n 12) 5))) 
			            (setf (elt sieve n) (not (elt sieve n)))))
		        (let ((n (+ (* 3 (expt i 2)) (expt j 2))))
    			    (when (and (<= n limit) (= (mod n 12) 7))
			            (setf (elt sieve n) (not (elt sieve n)))))
		        (if (> i j) 
			        (let ((n (- (* 3 (expt i 2)) (expt j 2))))
			            (when (and (<= n limit) (= (mod n 12) 11))
				            (setf (elt sieve n) (not (elt sieve n))))))))
	    (loop for index from 5 to factor do
            (if (elt sieve index)
		        (loop for jndex from (expt index 2) to limit by (expt index 2) do
			        (setf (elt sieve jndex) nil))))
	    (loop for index from 7 to limit do
		    (if (elt sieve index)
		        (vector-push-extend index results)))
	    (return-from atkin-sieve (merge 'list (sort results #'<) #() #'< ))))

(defun main ()
    (let ((primes-list (atkin-sieve 140000))
          (i 1)(j 2)(k 3)(l 4))
        (loop while t do
            (let ((count-i 0)(count-j 0)(count-k 0)(count-l 0))
                (loop for factor-i in (factors i) do
                    (if (member factor-i primes-list) (incf count-i)))
                (loop for factor-j in (factors j) do
                    (if (member factor-j primes-list) (incf count-j))) 
                (loop for factor-k in (factors k) do 
                    (if (member factor-k primes-list) (incf count-k))) 
                (loop for factor-l in (factors l) do
                    (if (member factor-l primes-list) (incf count-l)))
                (when (and (= count-i 4)(= count-j 4)(= count-k 4)(= count-l 4))
                    (format t "~d ~d ~d ~d~%" i j k l)
                    (return))
                (incf i)
                (incf j)
                (incf k)
                (incf l)))))
