class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        m = len(obstacleGrid[0])
        n = len(obstacleGrid)
        paths = [[0 for col in range(m)] for row in range(n)]
        if not obstacleGrid[0][0]:
        	paths[0][0] = 1
        else:
        	paths[0][0] = 0
        for row in range(1,n):
        	if paths[row-1][0] == 1 and obstacleGrid[row][0] != 1:
        		paths[row][0 ] = 1
        for col in range(1,m):
        	if paths[0][col-1] == 1 and obstacleGrid[0][col] != 1:
        		paths[0][col] = 1

        for row in range(1,n):
        	for col in range(1,m):
        		if obstacleGrid[row][col] == 1:
        			paths[row][col] = 0
        		else:
        			paths[row][col] = paths[row-1][col] + paths[row][col-1]

        return paths[n-1][m-1]
        
def main():
    sol = Solution()
    obstacleGrid = [[0,0,0],[0,1,0],[0,0,0],[0,0,0]]
    print(sol.uniquePathsWithObstacles(obstacleGrid))

if __name__ == "__main__":
    main()
