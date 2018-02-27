#!/usr/bin/python
class Solution:
    # 
    def letterCombinations(self, digits):
        letters = {2:'abc',3:'def',4:'ghi',5:'jkl',6:'mno',7:'pqrs',8:'tuv',9:'wxyz'}
        print(letters)
        return []
    
def main():
    test = Solution()
    print(test.letterCombinations(23))
    #print(test.letterCombinations(13))
    #print(test.letterCombinations(131))
    #print(test.letterCombinations(562))


if __name__ == "__main__":
    main()
