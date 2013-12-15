import Data.Char (digitToInt)

factorial :: Integer -> Integer
factorial 2 = 2
factorial num = num * (factorial (num - 1))

main = do
    print $ sum $ map digitToInt $ show (factorial 100)
