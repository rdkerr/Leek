class Solution:
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        paths = [[1 for col in range(m)] for row in range(n)]

        print(paths,m-1,n-1)
        for row in range(1,n):
        	for col in range(1,m):
        		paths[row][col] = paths[row-1][col] + paths[row][col-1]
        return paths[n-1][m-1]
        
def main():
    sol = Solution()
    print(sol.uniquePaths(3,3))
    print(sol.uniquePaths(4,9))
    print(sol.uniquePaths(7,3))

if __name__ == "__main__":
    main()
