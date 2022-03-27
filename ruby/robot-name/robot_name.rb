class Robot
  def self.forget
    @@names = [*'AA000'..'ZZ999'].shuffle.each
  end

  self.forget

  attr_reader :name

  def initialize
    reset
  end

  def reset
    @name = @@names.next
  end
end
