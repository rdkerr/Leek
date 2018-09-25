import math
class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        if n==1:    return str(n)
        nums = [i+1 for i in range(n)]
        f,t,k1=[1,1],"",k
        for i in range(2,n):  f+=[f[i-1]*i]
        for i in range(n):
            k1,k2 = k1%f[n-i-1],k1//f[n-i-1]
            if k1==0:   
                t+=str(nums[k2-1])
                del nums[k2-1]
                t+="".join([str(i) for i in nums[::-1]])
                return t
            t+=str(nums[k2])
            del nums[k2]
        return t
        
def main():
    sol = Solution()
    print(sol.getPermutation(3,3))
    print(sol.getPermutation(4,9))
    print(sol.getPermutation(5,3))

if __name__ == "__main__":
    main()
