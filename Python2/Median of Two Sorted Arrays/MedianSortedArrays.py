#!/usr/bin/python
#There are two sorted arrays nums1 and nums2 of size m and n respectively.
#Find the median of the two sorted arrays. The overall run time complexity
#should be O(log (m+n)).

def main():
    nums1 = [3,4,5,6,7,8,9,10]
    nums2 = [1,2]
    print findMedianSortedArrays(nums1,nums2)
    #print other(nums1,nums2)

def other(nums1,nums2):
    n = len(nums1)
    m = len(nums2)
    j = k = 0
    for i in xrange(((n+m)/2)-1):
        if nums1[j] < nums2[k]:
            if j < n-1:
                j+=1
            else:
                k+=1
        else:
            if k < m-1:
                k+=1
            else:
                j+=1
    print j,k
    if (n+m) % 2 == 1:
        return max(nums1[j],nums2[k])/1.0
    else:
        return (nums1[j]+nums2[k])/2.0

def findMedianSortedArrays(nums1, nums2):
    n = len(nums1)
    m = len(nums2)
    if len(nums2) == 0:
        if n % 2 == 1:
            return nums1[n/2]/1.0
        else:
            return (nums1[n/2]+nums1[(n/2)-1])/2.0
    if len(nums1) == 0:
        if n % 2 == 1:
            return nums2[n/2]/1.0
        else:
            return (nums2[n/2]+nums2[(n/2)-1])/2.0
    if len(nums2) == 1:
        nums3 = nums1
        nums1 = nums2
        nums2 = nums3
        n = len(nums1)
        m = len(nums2)
    if n==1:
        if m == 0:
            return nums1[0]/1.0
        elif m == 1:
            return (nums1[0] + nums2[0])/2.0
        elif m % 2 == 0:
            if nums1[0] < nums2[m/2]:
                return max(nums1[0],nums2[(m/2) - 1])/1.0
            else:
                return min(nums1[0],nums2[m/2])/1.0
        else:
            if nums1[0] == nums2[m/2]:
                return nums1[0]/1.0
            elif nums1[0]< nums2[m/2]:
                return (max(nums1[0],nums2[(m/2) - 1]) + nums2[m/2])/2.0 
            else:
                return (min(nums1[0],nums2[(m/2)]) + min(nums2[(m/2)+1],nums1[0]))/2.0
    front = 0
    back = n
    while (front <= back):
        xPart = (front + back) / 2      #xPart updated by removing half of lists at a time
        yPart = (n + m + 1)/2 - xPart   #Therefore O(log(n))
                                        #No additional space needed O(1)
        print "F",front, back    
        #Check numbers around partitions
        print "X",xPart, yPart
        if yPart > m:
            yPart = m
            xPart+=1
        elif yPart < 0:
            yPart = 0
            xPart -=1
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
        #correct partition
        print xLeft, xRight, yLeft, yRight
        if (xLeft <= yRight and yLeft <= xRight):
            if (n + m) % 2 == 0:
                return (max(xLeft,yLeft) + min(xRight, yRight))/2.0
            else:
                return max(xLeft,yLeft)/1.0
        elif xLeft > yRight:
            back = xPart - 1
        else:
            front = xPart + 1

if __name__ == "__main__":
    main()
