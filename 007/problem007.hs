isPrime :: Int -> Int -> Bool
isPrime index num
    | index <= floor (sqrt (fromIntegral num)) = 
        if rem num index == 0 && index /= num then
            False
        else
            isPrime (index + 1) num
    | otherwise = True

getNPrimes :: Int -> Int -> Int -> Int
getNPrimes current count limit 
    | count <= limit =
        if isPrime 2 current then
            getNPrimes (current + 1) (count + 1) limit
        else
            getNPrimes (current + 1) count limit
    | otherwise = current

main = do
    print ((getNPrimes 1 0 10001) - 1)
    
