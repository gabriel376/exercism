function leap_year(year)
   local function divisible_by(n) return year % n == 0 end
   return divisible_by(400) or (divisible_by(4) and not divisible_by(100))
end

return leap_year
