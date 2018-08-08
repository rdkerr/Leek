# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if intervals == [] or len(intervals)==1:
        	return intervals
        # intervals.sort(key = lambda x: x.start)
        start = intervals[0]
        result = []
        for i in range(1,len(intervals)):
        	if intervals[i][0] <= start[1]:
        		start[1] = max(intervals[i][1],start[1])
        	else:
        		result.append(start)
        		start = intervals[i]
        result.append(start)
        return result
        
def main():
    sol = Solution()
    print(sol.merge([[1,3],[2,6],[8,10],[15,18]]))
    print(sol.merge([[1,4],[4,5]])) 

if __name__ == "__main__":
    main()
