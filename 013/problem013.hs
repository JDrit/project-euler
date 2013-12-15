import System.IO
import Data.Digits

main = do
    handle <- openFile "numbers.txt" ReadMode
    -- result <- sumChars handle
    contents <- hGetContents handle
    print $ take 10 $ digits 10 $ sum $ map (\x -> read x :: Integer) (lines contents)
    hClose handle
  
