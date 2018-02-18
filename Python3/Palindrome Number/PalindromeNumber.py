#!/usr/bin/python
#Determine whether an integer is a palindrome. Do this without extra space.
class Solution:
    def isPalindrome(self, x):
        if x < 0:
            return False
        powerOfTen = 1
        size = 1
        while x / size >= 10:
            powerOfTen+=1
            size*=10           
        left = x
        right = 0
        print(powerOfTen,size)
        while powerOfTen > 1:
            left = x / size
            right = x % 10
            if left != right:
                return False
            x%=size
            x/=10
            size/=100
            powerOfTen-=2
        return True
    
def main():
    test = Solution()
    print(test.isPalindrome(1))
    print(test.isPalindrome(13))
    print(test.isPalindrome(131))
    print(test.isPalindrome(13154))


if __name__ == "__main__":
    main()
