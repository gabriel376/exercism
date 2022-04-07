module ArmstrongNumbers (armstrong) where

digits :: Integral a => a -> [a]
digits 0 = []
digits n = digits (n `div` 10) ++ [n `mod` 10]

armstrong :: Integral a => a -> Bool
armstrong n = n == sum [x ^ ex | x <- xs]
    where xs = digits n
          ex = length xs
