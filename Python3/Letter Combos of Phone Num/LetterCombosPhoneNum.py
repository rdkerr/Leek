#!/usr/bin/python
class Solution:
    # O(n^2) time complexity
    def letterCombinations(self, digits):
        if len(digits)==0:
            return []
        letters = {'2':'abc','3':'def','4':'ghi','5':'jkl',
                   '6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}
        result = []
        result.append('')
        for digit in digits:
            size = len(letters[digit])
            temp = []
            for res in result:
                temp.append(res + letters[digit][0])
                temp.append(res + letters[digit][1])
                temp.append(res + letters[digit][2])
                if len(letters[digit]) > 3:
                    temp.append(res + letters[digit][3])
            result = temp    
        return result
    
def main():
    test = Solution()
    print(test.letterCombinations('234'))



if __name__ == "__main__":
    main()
