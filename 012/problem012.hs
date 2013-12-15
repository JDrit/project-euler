factors :: Int -> Int
factors n = length $ [x | x <- [2..s], n `mod` x == 0] where s = floor (sqrt $ fromIntegral n)

loop :: Int -> Int -> Int
loop current index
    | len > 500 = current
    | otherwise = loop (index + current) (index + 1)
    where len = 2 * factors (current) + 2

main = do
    print $ loop 1 2
