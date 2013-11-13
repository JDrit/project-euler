
factorCount :: Int -> Int -> Int -> Int
factorCount num index amount 
    | index == floor (sqrt (fromIntegral num)) = 2 * amount
    | rem num index == 0 = 
        factorCount num (index + 1) (amount + 1)
    | otherwise = 
        factorCount num (index + 1) amount

getFactors num index
    | factorCount num 1 0 > 500 = num
    | otherwise = 
        getFactors (num + index) (index + 1)

main = do
    print (getFactors 1 2)
