# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}
def three_sum_closest(nums, target)
  closest = 2**32 - 1
  sorted = nums.sort
  length = nums.size - 3
  for i in 0..length
    front = i+1
    back = nums.size-1
    while front < back
      sum = sorted[i] + sorted[front] + sorted[back]
      if (closest - target).abs > (sum - target).abs
          closest = sum
        end  
      if sum > target  
        back= back - 1
      elsif sum < target
        front  = front + 1
      else
        return sum
      end
    end
  end
  return closest
end

s = [1,1,1,0]
puts three_sum_closest(s,100)