class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
     	words = s.split()
     	if not words:
     		return 0
     	else:
	     		return len(words[-1])

def main():
    sol = Solution()
    print(sol.lengthOfLastWord("Hello World"))

if __name__ == "__main__":
    main()
