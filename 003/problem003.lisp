(defun is-prime (n)
  (loop for i from 2 below (sqrt n) do
        (if (and (= (mod n i) 0) (/= i n))
          (return-from is-prime nil)))
  (return-from is-prime t))

(defun main ()
  (let ((number 600851475143))
    (loop for i from (truncate (sqrt number)) above 0 do
          (if (and (is-prime i) (= (mod number i) 0))
            (print i)))))
