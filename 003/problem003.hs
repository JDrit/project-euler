isPrime :: Int -> Int -> Bool
isPrime index num
    | index <= floor (sqrt (fromIntegral num)) = 
        if rem num index == 0 && index /= num then
            False
        else
            isPrime (index + 1) num
    | otherwise = True

isPrimeWrapper :: Int -> Bool
isPrimeWrapper num = isPrime 2 num

findPrime :: Int -> Int -> Int
findPrime index num = 
    if index > 0 && isPrimeWrapper index && rem num index == 0 then
        index
    else
        findPrime (index - 1) num

findPrimeWrapper :: Int -> Int
findPrimeWrapper num = findPrime (floor (sqrt (fromIntegral num))) num

main = do
    print (findPrimeWrapper 600851475143)
