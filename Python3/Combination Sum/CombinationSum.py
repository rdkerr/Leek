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
        self.candidates = candidates.sort()
        self.target = target
        self.back([],candidates,0,0)
        return [[element for element in tup] for tup in self.result]
    
    def back(self, temp, cand, start,total):
        if total==self.target:
            self.result.add(tuple(temp))
        elif total > self.target:
                return
        else:
            for i in range(start,len(cand)):
                temp.append(cand[i])
                print(temp)
                newTotal = total + cand[i]
                self.back(temp,cand,i,newTotal)
                temp.pop()
                newTotal = newTotal - cand[i]

def main():
    sol = Solution()
    candidates = [2,3,5,6]
    target = 8
    print(sol.combinationSum(candidates,target))
       

if __name__ == "__main__":
    main()
