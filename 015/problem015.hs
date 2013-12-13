memo = replicate 20 (replicate 20 [])

pathCount :: Int -> Int -> Int -> Int -> Integer
pathCount r c row_max col_max = 
    if r == row_max && c == col_max then
        1
    else if r < row_max && c < col_max sthen
        (pathCount (r + 1) c row_max col_max) + (pathCount r (c + 1) row_max col_max)
    else if r < row_max then
        pathCount (r + 1) c row_max col_max
    else
        pathCount r (c + 1) row_max col_max

main = do
    print (pathCount 0 0 20 20)







