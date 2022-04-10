module SavingsAccount
  def self.interest_rate(balance)
    case balance
    when -Float::INFINITY...0    then -3.213
    when                0...1000 then +0.500
    when             1000...5000 then +1.621
    else                              +2.475
    end
  end

  def self.annual_balance_update(balance)
    balance + (balance * interest_rate(balance).abs / 100)
  end

  def self.years_before_desired_balance(current_balance, desired_balance)
    years = 0
    while current_balance < desired_balance do
      current_balance = annual_balance_update(current_balance)
      years = years + 1
    end
    years
  end
end
