primes :: [Integer]
primes = sieve [2..]
    where
        sieve (p:xs) = p : sieve [x | x <- xs, x `mod` p > 0]

main = do
    print $ sum $ takeWhile (< 2000000) primes
    
