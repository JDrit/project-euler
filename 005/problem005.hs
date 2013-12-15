problem005 :: Int -> Int
problem005 num = 
    if rem num 19 == 0 && 
        rem num 18 == 0 &&
        rem num 17 == 0 &&
        rem num 16 == 0 &&
        rem num 15 == 0 &&
        rem num 14 == 0 &&
        rem num 13 == 0 &&
        rem num 12 == 0 &&
        rem num 11 == 0 then
        num
    else
        problem005 (num + 20)

main = do
    print (problem005 20)
