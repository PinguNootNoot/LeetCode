import numpy as np
import math

def findMedianSortedArrays(nums1, nums2):
    """
    :type nums1: List[int]
    :type nums2: List[int]
    :rtype: float
    """
    numstr = nums1 + nums2
    numstr.sort()
    length = len(numstr)
    halfIdx = int(math.floor(len(numstr) / 2))
    if length % 2 == 1:
        median = float(numstr[halfIdx])
    else:
        median = float((numstr[halfIdx-1] + numstr[halfIdx]) / 2)
    
    return median


s1 = [1, 5, 3, 89, 7, 41]
s2 = [6, 45, 8, 4, 9, 651, 13, 156, 12, 15, 61, 84, 21]

print(findMedianSortedArrays(s1, s2))
