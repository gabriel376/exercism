module SumOfMultiples (sumOfMultiples) where

sumOfMultiples :: [Integer] -> Integer -> Integer
sumOfMultiples factors limit = sum multiples
  where multiples = filter isMultiple [1..limit-1]
        isMultiple number = any (number `divisibleBy`) factors
        number `divisibleBy` factor = factor > 0 && number `mod` factor == 0
