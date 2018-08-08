# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        intervals.append(newInterval)
        return self.merge(intervals)
    
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
    print(sol.insert([[1,3],[6,9]],[2,5]))
    print(sol.insert([[1,2],[3,5],[6,7],[8,10],[12,16]],[4,8])) 

if __name__ == "__main__":
    main()
