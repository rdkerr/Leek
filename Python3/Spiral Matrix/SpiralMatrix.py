import math
class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        m = len(matrix[0])
        n = len(matrix)
        row = 0
        col = 0
        for cycle in range(math.ceil(m/2)):
        	#Go right
        	for c in range(col,m):
        		print(row,c)
        		#print(matrix[row][c])
        	print()
        	m -= 1
        	for r in range(row+1,n):
        		print(r,m)
        	n -= 1
        	print(99,m,n)
        	for c in range(m-1,col-1,-1):
        		print(n,c)
        	print(222222)
        	for r in range(n-1,row,-1):
        		print(r,col)
        	row += 1
        	col += 1
        	#Go down
        	#Go left
        	#Go up
        	print(1111111111111111)
        
        
def main():
    sol = Solution()
    matrix =[[ 1, 2, 3, 1, 2, 3 ],[ 4, 5, 6, 4, 5, 6 ],[ 7, 8, 9, 7, 8, 9 ],[ 7, 8, 9, 7, 8, 9 ],[ 7, 8, 9, 7, 8, 9 ]]
    print(sol.spiralOrder(matrix))
    print(sol.spiralOrder([ [ 1, 2, 3 ], [ 4, 5, 6 ], [ 7, 8, 9 ]]))
       

if __name__ == "__main__":
    main()
