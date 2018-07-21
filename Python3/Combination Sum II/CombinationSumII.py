#!/usr/bin/python
#Given a collection of candidate numbers (candidates) and a target
#number (target), find all unique combinations in candidates where
#the candidate numbers sums to target.
#
#Each number in candidates may only be used once in the combination.
class Solution:
    def combinationSumII(self, candidates, target):
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
                if i > start and cand[i] ==  cand[i-1]:
                    continue
                temp.append(cand[i])
                print(temp)
                newTotal = total + cand[i]
                self.back(temp,cand,i+1,newTotal)
                temp.pop()
                newTotal = newTotal - cand[i]

def main():
    sol = Solution()
    candidates = [2,3,5,6]
    target = 8
    print(sol.combinationSumII(candidates,target))
       

if __name__ == "__main__":
    main()
