class Solution:
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        result = []
        for i in range(n):
        	result.append([0]*n)
        left = 0
        right = n - 1
        top = 0
        bot = n - 1
        count = 0
        while count < n * n:
            for col in range(left,right+1):
                count += 1
                result[top][col] = count
            top += 1
            for row in range(top,bot):
                count += 1
                result[row][right]=count
            right-=1
            if count < n * n:
                for col in range(right+1,left-1,-1):
                    count+= 1
                    result[bot][col] = count
                bot -= 1
            if count < n * n:
                for row in range(bot,top-1,-1):
                    count += 1
                    result[row][left] = count
                left += 1
        return result

def main():
    sol = Solution()
    print(sol.generateMatrix(3))
    print(sol.generateMatrix(4))
    print(sol.generateMatrix(5))

if __name__ == "__main__":
    main()
