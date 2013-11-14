import Data.Char (digitToInt)

factorial :: Integer -> Integer
factorial num =
    if num == 1 then
        num
    else
        num * (factorial $ num - 1)

main = do
    print $ sum $ map digitToInt $ show $ factorial 100
