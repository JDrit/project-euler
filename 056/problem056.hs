intToLst :: [Char] -> [Int]
intToLst [] = []
intToLst (x:xs) = [read [x] :: Int] ++ intToLst xs

loop :: Int -> Integer -> Integer -> Int
loop best a b 
    | b == 100 = best
    | best < new = loop new a (b + 1)
    | otherwise = loop best a (b + 1)
    where new = sum (intToLst (show (a^b)))

mainLoop :: Int -> Integer -> Integer -> Int
mainLoop best a b
    | a == 100 = best
    | best < new = mainLoop new (a + 1) b
    | otherwise = mainLoop best (a + 1) b
    where new = loop 0 a b

main = do 
    print (mainLoop 0 2 1)
        
    
    
