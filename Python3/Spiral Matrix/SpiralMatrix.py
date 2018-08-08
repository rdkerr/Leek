class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if matrix == []:
            return matrix
        result = []
        left = 0
        right = len(matrix[0])-1
        top = 0
        bot = len(matrix)-1
        total = len(matrix)*len(matrix[0])
        for row in matrix:
            print(row)
        while len(result) < total:
            for col in range(left,right+1):
                result.append(matrix[top][col])
            top += 1
            for row in range(top,bot+1):
                result.append(matrix[row][right])
            right -= 1
            if len(result) < total:
                for col in range(right,left-1,-1):
                    result.append(matrix[bot][col])
                bot -= 1
            if len(result) < total:
                for row in range(bot,top-1,-1):
                    result.append(matrix[row][left])
                left += 1
        return result
        
        
        
def main():
    sol = Solution()
    matrix =[[ 1, 2, 3, 1, 2, 3 ],[ 4, 5, 6, 4, 5, 6 ],[ 7, 8, 9, 7, 8, 9 ],[ 7, 8, 9, 7, 8, 9 ],[ 7, 8, 9, 7, 8, 9 ]]
    print(sol.spiralOrder(matrix))
    print(sol.spiralOrder([ [ 1, 2, 3 ], [ 4, 5, 6 ], [ 7, 8, 9 ]]))
       

if __name__ == "__main__":
    main()
