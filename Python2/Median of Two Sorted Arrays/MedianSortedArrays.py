#!/usr/bin/python
#There are two sorted arrays nums1 and nums2 of size m and n respectively.
#Find the median of the two sorted arrays. The overall run time complexity
#should be O(log (m+n)).

def main():
    nums1 = [1,4]
    nums2 = [2,3]
    print findMedianSortedArrays(nums1,nums2)

def findMedianSortedArrays(nums1, nums2):
    n = len(nums1)
    m = len(nums2)
    front = 0
    back = n
    while (front <= back):
        print front, back
        xPart = (front + back) / 2
        yPart = (n + m + 1)/2 - xPart
        print xPart, yPart
        #Check numbers around partitions
        if xPart == 0:
            xLeft = float('-inf')
        else:
            xLeft = nums1[xPart - 1]
        if xPart == 0:
            xRight = float('inf')
        else:
            xRight = nums1[xPart]
        if yPart == 0:
            yLeft = float('-inf')
        else:
            yLeft = nums2[yPart - 1]
        if yPart == 0:
            yRight = float('inf')
        else:
            yRight = nums2[yPart]
        print xLeft, xRight
        print yLeft, yRight
        #correct partition
        if (xLeft <= yRight and yLeft <= xRight):
            return (max(xLeft,yLeft) + min(xRight, yRight))/2.0
        elif xLeft > yRight:
            back = xPart - 1
        else:
            front = xPart + 1
        a = raw_input("...")
            
        
    
    return 0
    
if __name__ == "__main__":
    main()
