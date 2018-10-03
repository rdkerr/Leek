class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid[0])
        n = len(grid)
        paths = [[0 for col in range(m)] for row in range(n)]
        paths[0][0] = grid[0][0]
        for row in range(1,n):
        	paths[row][0] = grid[row][0] + paths[row-1][0]
        for col in range(1,m):
        	paths[0][col] = grid[0][col] + paths[0][col-1]
        for row in range(1,n):
        	for col in range(1,m):
        		paths[row][col] = grid[row][col] + min(paths[row-1][col],paths[row][col-1])
        return paths[n-1][m-1]
        
        
def main():
    sol = Solution()
    grid = [[1,3,1],[1,5,1],[4,2,1]]
    print(sol.minPathSum(grid))

if __name__ == "__main__":
    main()
