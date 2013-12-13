digs :: Integral x => x -> [x]
digs 0 = []
digs x = digs (x `div` 10) ++ [x `mod` 10]

factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n - 1)

goodNumber :: Int -> Bool
goodNumber num = sum [factorial x | x <- digs num] == num

loop :: Int -> Int
loop index 
    | index == 200000 = 0
    | goodNumber index == True = index + loop (index + 1)
    | otherwise = loop (index + 1)

main = do
    print $ loop 3
