
seqGen :: Int -> Int -> Int
seqGen value length
    | value == 1 = length + 1
    | rem value 2 == 0 = 
        seqGen (quot value 2) (length + 1)
    | otherwise = 
        seqGen (3 * value + 1) (length + 1)

findLongest :: Int -> Int -> Int -> Int
findLongest current starting best
    | current >= 1000000 = starting
    | seqGen current 0 > best = 
        findLongest (current + 1) (current) (seqGen current 0)
    | otherwise = 
        findLongest (current + 1) starting best

main = do
   print (findLongest 2 2 2) 
