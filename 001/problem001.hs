mult3n5 limit = sum [x | x <- [1..limit], (mod x 3 == 0 || mod x 5 == 0)]

main = do
    print (sum [x | x <- [1..1000], (mod x 3 == 0 || mod x 5 == 0)])

