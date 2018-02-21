#!/usr/bin/python
#Given an integer, convert it to a roman numeral.
#Input is guaranteed to be within the range from 1 to 3999.
class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        thousands = ["", "M", "MM", "MMM"]
        hundreds = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
        tens = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
        ones = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
        return thousands[num/1000] + hundreds[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];

    
    #Slower
    def slowerIntToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        res = ""
        roman =  ['I', 'IV', 'V', 'IX', 'X', 'XL', 'L', 'XC', 'C', 'CD', 'D', 'CM', 'M']
        values = [1,   4,     5,    9,   10,  40,   50,  90,  100,  400, 500, 900, 1000]
        for r, v in zip(reversed(roman), reversed(values)):
            res += num//v * r
            num %= v
        return res
    
    #Too slow
    def slowIntToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        roman =  ['I', 'IV', 'V', 'IX', 'X', 'XL', 'L', 'XC', 'C', 'CD', 'D', 'CM', 'M']
        values = [1,   4,     5,    9,   10,  40,   50,  90,  100,  400, 500, 900, 1000]
        res = ""
        for i in xrange(len(roman)):
            while num >= values[len(values)-i-1]:
                res += roman[len(roman) -i-1]
                num-=values[len(values)-i-1]
        return res
        
def main():
    nums1 = [3,4,5,6,7,8,9,10]
    nums2 = [1,2]
    s = Solution()
    for i in xrange(100,110):
        print s.intToRoman(i)

if __name__ == "__main__":
    main()
