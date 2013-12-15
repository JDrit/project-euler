sef :: Integer -> Integer -> Integer
sef num1 num2
    | num1 + num2 > 4000000 = 0
    | mod (num1 + num2) 2 == 0 = num1 + num2 + sef num2 (num1 + num2)
    | otherwise = sef num2 (num1 + num2)

main = do
    print (sef 0 1)

