require 'set'

class Sieve
  attr_reader :primes

  def initialize(n)
    numbers = Set[*2..n]
    (2..n).each{ |x| numbers.subtract((x+x..n).step(x)) }
    @primes = numbers.to_a
  end
end
