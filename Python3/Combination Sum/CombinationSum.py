#!/usr/bin/python
#Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
#The same repeated number may be chosen from candidates unlimited number of times.
#Note:
#All numbers (including target) will be positive integers.
#The solution set must not contain duplicate combinations.
#Example 1:
#Input: candidates = [2,3,6,7], target = 7,
#A solution set is:
#[
#  [7],
#  [2,2,3]
#]
#Example 2:
#Input: candidates = [2,3,5], target = 8,
#A solution set is:
#[
#  [2,2,2,2],
#  [2,3,3],
#  [3,5]
#]
class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        self.result = set()
        self.candidates = candidates
        self.target = target
        self.search()
        return list(result)

    def sub(self, cand):
        res =[]
        self.back(res,[],cand,0)
        return res
    
    def back(self, res, temp, cand, start):
        res.append(list(temp))
        print(res,temp,start)
        for i in range(start,len(cand)):
            temp.append(cand[i])
            self.back(res,temp,cand,i+1)
            temp.pop()

def main():
    sol = Solution()
    candidates = [2,3,5]
    target = 8
    print(sol.sub(candidates))
    #print(sol.combinationSum(candidates,target))
       

if __name__ == "__main__":
    main()
