 (defun prime-finder (num)
          (let ((count 0)
                (current 2)
                (primes (make-array 3 :fill-pointer 0 :adjustable t :element-type 'fixnum)))
                    (loop while (< count num) do 
                          (let ((valid-prime t))
                            (loop for x below (length primes) do
                                (when (= (mod current (elt primes x)) 0)
                                    (setf valid-prime nil)
                                    (return)))
                            (if valid-prime
                                (progn 
                                    (vector-push-extend current primes)
                                    (incf count)))
                            (incf current)))
                    (return-from prime-finder (- current 1))))
