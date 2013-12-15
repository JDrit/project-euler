sumSquares :: Int -> Int
sumSquares count 
    | count == 1 = 1
    | otherwise = count * count + sumSquares (count - 1)


main = do
    print ((sum [1..100])^2 - (sumSquares 100))
