require 'ostruct'

class BoutiqueInventory
  attr_reader :items

  def initialize(items)
    @items = items.map(&OpenStruct.method(:new))
  end

  def item_names
    @items.map(&:name).sort
  end

  def total_stock
    @items.sum(&(:quantity_by_size.to_proc >> :values.to_proc >> :sum.to_proc))
  end
end
