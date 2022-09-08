

def twoSum(nums, target):
    ans = [-1,-1]

    for i in range(0, len(nums)):
        for j in range(i+1, len(nums)):
            if(nums[i] + nums[j] == target):
                ans[0] = i
                ans[1] = j
                return ans

print twoSum([2, 7, 11, 15], 18)
    
