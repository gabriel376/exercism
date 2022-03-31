return function(limit)
   return coroutine.create(function()
         local marked = {}
         for x = 2, limit do
            if not marked[x] then coroutine.yield(x) end
            for y = 2*x, limit, x do marked[y] = true end
         end
   end)
end
