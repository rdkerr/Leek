class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sums = [0]*len(nums)
        sums[0] = nums[0]
        maxSum = sums[0]
        for i in range(1,len(nums)):
            sums[i] = max(nums[i], nums[i]+sums[i-1])
            if sums[i] > maxSum:
                maxSum = sums[i]
        return maxSum
        
def main():
    sol = Solution()
    nums = [-2,1,-3,4,-1,2,1,-5,4]
    print(sol.maxSubArray(nums))
       

if __name__ == "__main__":
    main()
