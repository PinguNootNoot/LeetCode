import math


def threeSum(nums):
    """
    :type nums: List[int]
    :rtype: List[List[int]]
    """
    outV = []

    nums.sort()
    for i in range(len(nums)-1):
        target = -nums[i]
        left = i + 1; right = len(nums) - 1
        while left < right:
            sum = nums[left] + nums[right]
            if sum == target:
                ans = sorted([nums[i],nums[left],nums[right]])
                if ans not in outV:
                    outV.append(ans)
                right -= 1
            elif sum < target:
                left += 1
                while nums[left] == nums[left-1]:
                    left += 1
                    if left > right: break
            else:
                right -= 1
                while nums[right] == nums[right+1]:
                    right -= 1
                    if left > right: break
        
    return outV


N = [-1,0,1,2,-1,-4]
print(threeSum(N))
