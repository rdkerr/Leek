# @param {String} str
# @return {Integer}
def my_atoi(str)
  stripped = str.lstrip
  userInput = stripped.match( /[+-]?\d+/)
  if stripped.match(/([+-]){1}\D+/) then
    return 0
  elsif stripped.match(/\A[\D&&[^+-]]\d/) then
    return 0
  end
  if userInput then
    number = userInput[0].to_i
    if number < -2147483648 then
      return -2147483648
    elsif number > 2147483647 then
       return 2147483647
    end
    return number 
  else
    return 0
  end  
end

userInput = gets
puts my_atoi(userInput)