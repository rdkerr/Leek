class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        reach = 0
        for i in range(len(nums)):
        	if i > reach:
        		return False
        	reach = max(reach,nums[i]+i)
        return True



def main():
    sol = Solution()
    print(sol.canJump([2,3,1,1,4]))
    print(sol.canJump([3,2,1,0,4])) 

if __name__ == "__main__":
    main()
