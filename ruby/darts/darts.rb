class Darts
  attr_reader :score

  def initialize(x, y)
    @score = case Math.hypot(x, y)
             when 0..1  then 10
             when 1..5  then 5
             when 5..10 then 1
             else            0
             end
  end
end
