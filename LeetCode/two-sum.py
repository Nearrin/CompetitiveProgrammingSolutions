class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m={}
        for i in range(len(nums)):
            if i:
                m[target-nums[i-1]]=i-1
            if nums[i] in m:
                return [m[nums[i]], i]
            
        
            
