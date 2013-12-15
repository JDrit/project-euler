import Data.Char (digitToInt) 

loop :: Int -> Int
loop index
    | index > 400000 = 0
    | index == result = index + loop (index + 1)
    | otherwise = loop (index + 1)
    where result = sum $ map (^5) $ map digitToInt $ show index

main = do
    print $ loop 2
