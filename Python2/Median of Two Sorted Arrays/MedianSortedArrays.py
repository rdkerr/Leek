#!/usr/bin/python
#There are two sorted arrays nums1 and nums2 of size m and n respectively.
#Find the median of the two sorted arrays. The overall run time complexity
#should be O(log (m+n)).

def main():
    nums1 = [3,4,5,6,7,8,9,10]
    nums2 = [1,2]
    print findMedianSortedArrays(nums1,nums2)


def findMedianSortedArrays(nums1, nums2):
    if len(nums1) > len(nums2):
        nums3 = nums1
        nums1 = nums2
        nums2 = nums3
    n = len(nums1)
    m = len(nums2)

    front = 0
    back = n
    while (front <= back):
        xPart = (front + back) / 2
        yPart = (n + m + 1) / 2 - xPart

        if xPart == 0:
            xLeft = float('-inf')
        else:
            xLeft = nums1[xPart - 1]
        if xPart == n:
            xRight = float('inf')
        else:
            xRight = nums1[xPart]

        if yPart == 0:
            yLeft = float('-inf')
        else:
            yLeft = nums2[yPart - 1]
        if yPart == m:
            yRight = float('inf')
        else:
            yRight = nums2[yPart]
        print xLeft, xRight, yLeft, yRight
        if (xLeft <= yRight and yLeft <= xRight):
            if (n+m)% 2 == 0:
                return (max(xLeft,yLeft) + min(xRight,yRight))/2.0
            else:
                return max(xLeft,yLeft)/1.0
        elif xLeft > yRight:
            back = xPart - 1
        else:
            front = xPart + 1

if __name__ == "__main__":
    main()
