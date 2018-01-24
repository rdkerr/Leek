#!/usr/bin/python
#Given an array of integers, return indices of the two numbers such that
#they add up to a specific target.
#
#You may assume that each input would have exactly one solution, and you
#may not use the same element twice.
#Example: Given [2,7,11,15], target = 9
#return 0, 1
def main():
    testList1 = [2, 7, 11, 15]
    testTarget1 = 9
    testList2 = [3, 4, 5, 8]
    testTarget2 = 12
    testList3 = [1, 15, 11, 13]
    testTarget3 = 26
    print(twoSum(testList1,testTarget1))
    print(twoSum(testList2,testTarget2))
    print(twoSum(testList3,testTarget3))
  
def twoSum(nums, target):
    numberMap = {}
    for i in range(len(nums)):
        complement = target - nums[i]
        if(nums[i] in numberMap):
            return [numberMap[nums[i]],i]
        numberMap[complement] = i
    


if __name__ == "__main__":
    main()
